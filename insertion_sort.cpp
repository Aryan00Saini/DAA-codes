#include<iostream>
#include<vector>
using namespace std;
void insertionsort(vector<int>&arr,int n){
    int shift = 0, comparison = 0;
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j=i-1;
        while(j>=0 ){
            comparison++;
            if(arr[j] > current){
            arr[j+1]=arr[j];
            shift++;
            j--;
            }
            else break;
        }
        arr[j+1]=current;
        shift++;
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
    insertionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<"["<<arr[i]<<"]";
    }
    return 0;
}