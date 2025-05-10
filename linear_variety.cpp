#include <iostream>
#include <vector>
using namespace std;

void linear_iteration_sorted(vector<int>& arr, int n, int key) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (arr[i] == key) {
            cout << "element found"<<endl;
            cout << "comparisons = " << count << endl;
            return;
        }
        if (arr[i] > key) {
            cout << "element not found"<<endl;
            cout << "comparisons = " << count << endl;
            return;
        }
    }
    cout << "element not found\n";
    cout << "comparisons = " << count << endl;
}

void linear_iteration_unsorted(vector<int>& arr, int n, int key) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (arr[i] == key) {
            cout << "element found"<<endl;
            cout << "comparisons = " << count << endl;
            return;
        }
    }
    cout << "element not found\n";
    cout << "comparisons = " << count << endl;
}

void linear_recursive_sorted(vector<int>& arr, int n, int key, int i,int count ) {
    if (i >= n) {
        cout << "Element not found"<<endl;
        cout << "Comparisons = " << count << endl;
        return;
    }
    if (arr[i] == key) {
        cout << "element found"<<endl;
        cout << "comparisons = " << count << endl;
        return;
    }
    if (arr[i] > key) {
        cout << "element not found"<<endl;
        cout << "comparisons = " << count << endl;
        return;
    }
    linear_recursive_sorted(arr, n, key, i+1, count+1);
}

void linear_recursive_unsorted(vector<int>& arr, int n, int key, int i, int count) {
    if (i >= n) {
        cout << "Element not found"<<endl;
        cout << "Comparisons = " << count << endl;
        return;
    }
    if (arr[i] == key) {
        cout << "element found"<<endl;
        cout << "comparisons = " << count << endl;
        return;
    }
    linear_recursive_unsorted(arr, n, key, i+1, count+1);
}

int main() {
    int n, key, testcase, choice;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the number of test cases: ";
    cin >> testcase;
    vector<int> arr(n);
    while (testcase > 0) {
        cout<<"\n1. linear iterartive with sorted array\n2. linear iterartive with unsorted array\n3. linear recurssive with sorted array\n4. linear recursive with sorted array"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter the values in sorted order: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                cout << "Enter the number you want to search: ";
                cin >> key;
                linear_iteration_sorted(arr, n, key);
                break;

            case 2:
                cout << "Enter the values in unsorted order: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                cout << "Enter the number you want to search: ";
                cin >> key;
                linear_iteration_unsorted(arr, n, key);
                break;

            case 3:
                cout << "Enter the values in sorted order: ";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                cout << "Enter the number you want to search: ";
                cin >> key;
                linear_recursive_sorted(arr, n, key,0,1);
                break;

            case 4:
            cout << "Enter the values in unsorted order: ";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            cout << "Enter the number you want to search: ";
            cin >> key;
            linear_recursive_unsorted(arr, n, key,0,1);
            break;

            default:
                cout << "Invalid choice";
        }
        testcase--;
    }
    return 0;
}
