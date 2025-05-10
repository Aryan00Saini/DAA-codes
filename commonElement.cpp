#include<iostream>
#include<vector>
using namespace std;

void commonElement(vector<int>&arr1,vector<int>&arr2) {
    int i = 0, j = 0;
    vector<int> output;
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] == arr2[j]){
            output.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    for (int i = 0; i < output.size(); i++) {
        cout << "["<<output[i]<<"]";
    }
}

int main() {
    int n,m;
    cout << "Enter the size of the 1st array: ";
    cin >> n;
    vector<int> arr1(n);
    cout << "Enter elements for 1st array : ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    cout << "Enter the size of 2nd array: ";
    cin >> m;
    vector<int> arr2(m);
    cout << "Enter elements for 2nd array : ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    commonElement(arr1,arr2);
    return 0 ;
}