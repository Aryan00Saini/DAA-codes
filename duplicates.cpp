#include<iostream>
#include<vector>
using namespace std;

int Binary_search1st(vector<int>& arr, int n, int key){
    int low = 0, high = n-1, first;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] == key){ 
            first = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return first;
}

int Binary_search2nd(vector<int>& arr, int n, int key){
    int low = 0, high = n-1, last;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] == key){ 
            last = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return last;
}

int main(){
    int n, key, testcase;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter the values in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the number you want to search: ";
    cin >> key;
    int f = Binary_search1st(arr, n, key);
    int l = Binary_search2nd(arr, n, key);
    int occurence = l - f + 1;
    cout << "occurence : " << occurence << endl;
    return 0;
}