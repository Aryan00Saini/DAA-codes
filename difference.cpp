#include <iostream>
#include <vector>
using namespace std;
void FindPair(vector<int>&arr, int n, int K) {
    int i = 0, j = 1;
    while (j < n) {
        int diff = arr[j] - arr[i];
        if (diff == K) {
            cout << "Pair found: (" << arr[i] << ", " << arr[j] << ")" << endl;
            return; 
        } 
        else if (diff < K) {
            j++; 
        } 
        else {
            i++;
        }

        if (i == j) 
            j++;
    }

    cout << "No pair found" << endl;
}

int main() {
    int n,K;
    cout<<"enter the size of array : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"enter the value in array : ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"enter key value : ";
    cin>>K;
    FindPair(arr, n, K);
    return 0;
}
