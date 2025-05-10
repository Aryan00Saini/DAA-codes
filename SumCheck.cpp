#include<iostream>
#include<vector>
using namespace std;

void sum_check(vector<int>& arr, int n){
    for(int k = n - 1; k > 2; k--){
        int i = 0, j = n - 2;
        while(i < j){
            int sum = arr[i] + arr[j];
            if(sum == arr[k]){
                cout << "index : "<<"["<<i<<"]"<< "["<< j <<"]"<< "["<< k <<"]"<<endl;
                break; 
            }
            else if(sum < arr[k]){
                j--;
            }
            else i++;
        }
    }
    return;
}

int main(){
    int n, key, testcase, choice;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter the values in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sum_check(arr, n);
    return 0;
}