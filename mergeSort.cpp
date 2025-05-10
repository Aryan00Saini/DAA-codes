#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& arr, int low, int mid, int high, int& comparisons, int& inversions) {
    int i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        comparisons++;  
        if (arr[i] <= arr[j]) {
            i++;
        } 
        else {
            int value = arr[j];
            int index = j;
            while (index > i) {  
                arr[index] = arr[index - 1];  
                index--;
            }
            arr[i] = value;  
            i++;  
            mid++;  
            j++;  
            inversions += (mid - i);  
        }
    }
}
void mergeSort(vector<int>& arr, int low, int high, int& comparisons, int& inversions) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid, comparisons, inversions);
        mergeSort(arr, mid + 1, high, comparisons, inversions);
        merge(arr, low, mid, high, comparisons, inversions);
    }
}
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int comparisons = 0, inversions = 0;
    mergeSort(arr, 0, n - 1, comparisons, inversions);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << "[" << arr[i] << "] ";
    }
    cout << "\nNumber of comparisons: " << comparisons;
    cout << "\nNumber of inversions: " << inversions << endl;
    return 0;
}
