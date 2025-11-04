#include <iostream>
#include <string>
using namespace std;
struct FruitNode 
{
    string type;
    string name;
    int rating;
    FruitNode* next = nullptr;
    FruitNode* prev = nullptr;
};

class FruitInventory
{
  private:
    FruitNode* head = nullptr;
    FruitNode* tail = nullptr;

  public:
    ~FruitInventory() 
    {
        FruitNode* current = head;
        while (current) 
        {
            FruitNode* next = current->next;
            delete current;
            current = next;
        }
    }
    void addFruit(const string& t, const string& n, int r) 
    {
        FruitNode* newNode = new FruitNode{t, n, r};
        if (!head) 
        {
            head = tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void deleteNode(const string& name) 
    {
        FruitNode* current = head;
        while (current) 
        {
            if (current->name == name) 
            {
                if (current->prev) current->prev->next = current->next;
                else head = current->next;
                
                if (current->next) current->next->prev = current->prev;
                else tail = current->prev;
                
                delete current;
                return;
            }
            current = current->next;
        }
    }
    
    void editNode(const string& name, int newRating) 
    {
        FruitNode* current = head;
        while (current) 
        {
            if (current->name == name) 
            {
                current->rating = newRating;
                return;
            }
            current = current->next;
        }
    }
    void searchHighRating(int minRating = 8) const 
    {
        cout << "\n--- High Rated Fruits (R >= 8) ---" << endl;
        FruitNode* current = head;
        bool found = false;
        while (current) 
        {
            if (current->rating >= minRating) 
            {
                cout << current->name << " (" << current->type << ") [R: " << current->rating << "]" << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) cout << "None found." << endl;
    }
    void displayAll() const 
    {
        cout << "\n--- Inventory List ---" << endl;
        FruitNode* current = head;
        if (!head) 
        {
            cout << "Empty." << endl;
            return;
        }
        while (current) 
        {
            cout << current->type << " - " << current->name << " (R: " << current->rating << ")" << endl;
            current = current->next;
        }
    }
};
int main() {
    FruitInventory inventory;
    inventory.addFruit("dryfruit", "Almond", 9);
    inventory.addFruit("citrusfruit", "Orange", 7);
    inventory.addFruit("stonefruit", "Peach", 8);
    inventory.addFruit("berryfruit", "Strawberry", 10);
    inventory.addFruit("tropical", "Mango", 5);
    inventory.displayAll();
   inventory.editNode("Mango", 9); // Mango rating changed from 5 to 9

    // Delete (3)
    inventory.deleteNode("Orange");

    // Display all (6)
    inventory.displayAll();

    // Search (5)
    inventory.searchHighRating();

    return 0;
}