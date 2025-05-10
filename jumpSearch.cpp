#include <iostream>
#include <vector>
using namespace std;

int jump_search(vector<int>&arr, int n, int key) {
    int j = 0;
    if (arr[0] == key) {
        return 1;
    }
    int i = 1;
    while(i < n && arr[i] <= key) {
        i = i * 2;
    }
    int fb = i/2;
    int lb = i < n ? i:n-1;
    for(j = fb ; j < lb ; j++){
        if(arr[j] == key) return 1;
    }
    return 0;
}

int main() {
    int n, key;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int>arr(n);
    cout<<"enter elements in array";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout << "Number you want to search";
    cin >> key;
    int result = jump_search(arr, n, key);
    if(result == 1) cout<<"element found";
    else cout<<"not found";
    return 0;
}