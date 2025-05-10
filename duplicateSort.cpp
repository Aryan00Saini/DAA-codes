#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void duplicate(vector<int>&arr,int n){
    for(int i = 0;i < n;i++){ 
        if(arr[i] == arr[i+1]){
            cout<<"duplicate elements are present"<<endl;
            return;
        }
    }   
    cout<<"no duplicates in array"<<endl;
}
int main(){
    int n;
    cout<<"enter the value of n : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"enter the elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    duplicate(arr,n);
    for(int i=0;i<n;i++){
        cout<<"["<<arr[i]<<"]";
    }
    return 0;
}