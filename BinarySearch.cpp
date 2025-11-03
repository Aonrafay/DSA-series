#include<iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key)  // Fixed: added 'int' before arr[], corrected spelling
{
    int s = 0;        // Fixed: start should be 0
    int e = n - 1;    // Fixed: end should be n-1 (last index)
    
    while(s <= e)     // Fixed: now s=0 and e=n-1, so this condition makes sense
    {
        int mid = (s + e) / 2;
        
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] > key)
        {
            e = mid - 1;  // Search in left half
        }
        else
        {
            s = mid + 1;  // Search in right half
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int key;
    cin >> key;
    
    cout << BinarySearch(arr, n, key);  // Fixed: corrected spelling
    return 0;
}