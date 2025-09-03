#include <iostream>
using namespace std;

// -------- Sorting Algorithms --------

// Selection Sort
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for(int p = 0; p < k; p++) arr[left + p] = temp[p];
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// -------- Searching Algorithms --------

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) return i; // found
    }
    return -1; // not found
}

// Binary Search (array sorted ???? ?????)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// -------- Utility Function --------
void displayArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// -------- Main Program --------
int main() {
    int n, choice, key;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                selectionSort(arr, n);
                cout << "Array after Selection Sort: ";
                displayArray(arr, n);
                break;

            case 2:
                mergeSort(arr, 0, n-1);
                cout << "Array after Merge Sort: ";
                displayArray(arr, n);
                break;

            case 3:
                cout << "Enter element to search: ";
                cin >> key;
                if(linearSearch(arr, n, key) != -1)
                    cout << "Element found!\n";
                else
                    cout << "Element not found.\n";
                break;

            case 4:
                cout << "Enter element to search: ";
                cin >> key;
                if(binarySearch(arr, n, key) != -1)
                    cout << "Element found!\n";
                else
                    cout << "Element not found.\n";
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 5);

    return 0;
}

