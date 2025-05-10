#include<iostream>
#include<vector>
using namespace std;

void countsort(vector<char>& str, int n) {
    vector<int>count(256,0);
    for (int i = 0; i < n; i++) {
        count[str[i]]++;
    }
    cout<<"duplicate elements : ";
    for (int i = 0; i < 256; i++) {
        if(count[i]>1){
            cout<<(char)i<<" - " << count[i]<<endl;
        }
    }
}

int main() {
    vector<char> str;
    int n;
    char value;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the character : ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        str.push_back(value);
    }
    countsort(str,n);
    return 0;
}