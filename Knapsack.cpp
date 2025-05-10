#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int main(){
    int a,b,n,capacity;
    cout<<"enter the size of array :";
    cin>>n;
    cout<<"enter the elements(price,item) : ";

    vector<pair<double,double>> arr;

    for(int i = 0;i<n;i++){
        cin>>a>>b;
        arr.push_back({a,b});
    }

    vector<double>final;
    for(auto i : arr ){
        double per_it = (i.first)/(i.second);
        final.push_back(per_it);
    }

    cout<<"capacity : ";
    cin>>capacity;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(final[i] < final[j]){
                swap(final[i],final[j]);
                swap(arr[i],arr[j]);
            }
        }
    }
    double total = 0;
    double temp = 0;
    int price_max = 0;
    for(auto i : arr){
        temp += i.second;
        if( temp < capacity){
            total += i.second;
            price_max += i.first;
        }
        else{
            int diff = capacity - total;
            price_max += ((i.first/i.second)* diff);
            break;
        }

    }
    cout<< "max price : " <<price_max; 
    return 0;
}