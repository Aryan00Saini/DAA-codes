#include<iostream>
#include<vector>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(vector<int>&arr,int n){
    int comparison = 0,shift = 0;
    for(int i=0;i<n;i++){
        int minIndex = i;
        for(int j = i+1; j < n;j++){
            comparison++;
            if(arr[j] < arr[minIndex]){
            minIndex = j;
            }
        }
        if(i!=minIndex){
            swap(arr[i],arr[minIndex]);
            shift++;
        }
    }
    cout<<"comparison : "<<comparison<<endl;
    cout<<"shift : "<<shift<<endl;
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
    selection_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<"["<<arr[i]<<"]";
    }
    return 0;
}