#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b, int &swaps) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

int partition(vector<int> &arr, int low, int high, int &comparisons, int &swaps) {
    int i = low - 1;
    int pivot = arr[high];

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j], swaps);
        }
    }
    swap(&arr[i + 1], &arr[high], swaps);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high, int &comparisons, int &swaps) {
    if (low < high) {
        int p = partition(arr, low, high, comparisons, swaps);
        quickSort(arr, low, p - 1, comparisons, swaps);
        quickSort(arr, p + 1, high, comparisons, swaps);
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
    int comparisons = 0, swaps = 0;
    quickSort(arr, 0, n - 1, comparisons, swaps);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << "[" << arr[i] << "] ";
    }
    cout << "\nTotal comparisons: " << comparisons;
    cout << "\nTotal swaps: " << swaps << endl;
    return 0;
}
