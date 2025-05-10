#include<iostream>
#include<vector>
using namespace std;

int Binary_search(vector<int>& arr, int n, int key){
    int low = 0, high = n-1;
    int count = 0;
    while(low<=high){
        count ++;
        int mid = low + (high - low)/2;
        if(arr[mid] == key){
            cout<<"comparison : "<<count<<endl;
            return 1;
        }
        if (arr[mid] < key) low = mid + 1; 
        else high = mid - 1;
    }
    cout<<"comparison : "<<count<<endl;
    return -1;
}

int Binary_searchRecursive(vector<int>& arr, int n, int low, int high, int key,int count){
    if(low > high){
        cout<<"comparison : "<<count<<endl;
        return -1;
    }
    int mid=low + (high - low)/2;
    if(arr[mid] == key){
        cout<<"comparison : "<<count<<endl;
        return mid;
    }
    if(arr[mid] < key) return Binary_searchRecursive(arr, n, mid+1, high, key, count+1);
    else return Binary_searchRecursive(arr, n, low, mid-1, key,count+1);
}

int main(){
    int n, key, testcase, choice, result, count;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the number of test cases: ";
    cin >> testcase;
    vector<int>arr(n);
    
    while (testcase > 0) {
        cout<<"\n1. Binary Search Iterative\n2. Binary Search Recursive"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cout << "Enter the values in sorted order: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Enter the number you want to search: ";
        cin >> key;

        switch (choice) {
            case 1:
                result = Binary_search(arr, n, key);
                if (result != -1) {
                    cout << "Element found" << endl;
                } else {
                    cout << "Not found" << endl;
                }
                break;

            case 2:
                result = Binary_searchRecursive(arr, n,  0, n - 1, key,1);
                if (result != -1) {
                    cout << "Element found "<< endl;
                } else {
                    cout << "Element not found" << endl;
                }
                break;
            default:
                cout << "Invalid choice";
        }
        testcase--;
    }
    return 0;
}