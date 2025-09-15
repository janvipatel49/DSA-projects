#include <iostream>
#include <vector>
using namespace std;

// ------------------ Node Structure ------------------
struct Node {
    int value;       // data stored
    Node* next;      // pointer to next node
};

// ------------------ Linked List Class ------------------
class MyList {
private:
    Node* head;   // first node pointer

public:
    // Constructor
    MyList() {
        head = NULL;
    }

    // Add a new node at the end
    void addLast(int num) {
        Node* fresh = new Node;
        fresh->value = num;
        fresh->next = NULL;

        if (head == NULL) {
            head = fresh;  // first node
        } else {
            Node* mover = head;
            while (mover->next != NULL) {
                mover = mover->next;
            }
            mover->next = fresh;
        }
        cout << "Added " << num << " into list.\n";
    }

    // Remove a node by its value
    void removeVal(int num) {
        if (head == NULL) return; // list is empty

        if (head->value == num) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Removed " << num << " from list.\n";
            return;
        }

        Node* mover = head;
        while (mover->next != NULL && mover->next->value != num) {
            mover = mover->next;
        }
        if (mover->next != NULL) {
            Node* trash = mover->next;
            mover->next = mover->next->next;
            delete trash;
            cout << "Removed " << num << " from list.\n";
        } else {
            cout << "Value not found in list.\n";
        }
    }

    // Show all values in linked list
    void showList() {
        Node* mover = head;
        cout << "List Items: ";
        while (mover != NULL) {
            cout << mover->value << " -> ";
            mover = mover->next;
        }
        cout << "NULL\n";
    }
};

// ------------------ Merge Sort ------------------
void mergeParts(vector<int>& a, int l, int mid, int r) {
    int leftSize = mid - l + 1;
    int rightSize = r - mid;

    vector<int> left(leftSize), right(rightSize);
    for (int i = 0; i < leftSize; i++) left[i] = a[l + i];
    for (int j = 0; j < rightSize; j++) right[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) a[k++] = left[i++];
        else a[k++] = right[j++];
    }
    while (i < leftSize) a[k++] = left[i++];
    while (j < rightSize) a[k++] = right[j++];
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        mergeParts(a, l, mid, r);
    }
}

// ------------------ Quick Sort ------------------
int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// ------------------ Binary Search ------------------
int binarySearch(vector<int>& a, int key) {
    int left = 0, right = a.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// ------------------ Main Menu ------------------
int main() {
    MyList mylist;
    vector<int> nums;
    int option;

    do {
        cout << "\n==== MAIN MENU ====\n";
        cout << "1. Add into Linked List\n";
        cout << "2. Delete from Linked List\n";
        cout << "3. Show Linked List\n";
        cout << "4. Enter Array\n";
        cout << "5. Merge Sort Array\n";
        cout << "6. Quick Sort Array\n";
        cout << "7. Binary Search in Array\n";
        cout << "0. Exit\n";
        cout << "Choose option: ";
        cin >> option;

        if (option == 1) {
            int n;
            cout << "Enter number: ";
            cin >> n;
            mylist.addLast(n);
        }
        else if (option == 2) {
            int n;
            cout << "Enter number to delete: ";
            cin >> n;
            mylist.removeVal(n);
        }
        else if (option == 3) {
            mylist.showList();
        }
        else if (option == 4) {
            int size;
            cout << "How many elements? ";
            cin >> size;
            nums.resize(size);
            cout << "Enter values: ";
            for (int i = 0; i < size; i++) cin >> nums[i];
        }
        else if (option == 5) {
            if (!nums.empty()) {
                mergeSort(nums, 0, nums.size() - 1);
                cout << "Array after Merge Sort: ";
                for (int i = 0; i < nums.size(); i++) {
                    cout << nums[i] << " ";
                }
                cout << endl;
            } else {
                cout << "Array is empty.\n";
            }
        }
        else if (option == 6) {
            if (!nums.empty()) {
                quickSort(nums, 0, nums.size() - 1);
                cout << "Array after Quick Sort: ";
                for (int i = 0; i < nums.size(); i++) {
                    cout << nums[i] << " ";
                }
                cout << endl;
            } else {
                cout << "Array is empty.\n";
            }
        }
        else if (option == 7) {
            if (!nums.empty()) {
                int key;
                cout << "Enter number to find: ";
                cin >> key;
                int pos = binarySearch(nums, key);
                if (pos != -1) cout << "Found at index " << pos << endl;
                else cout << "Not found.\n";
            } else {
                cout << "Array is empty.\n";
            }
        }

    } while (option != 0);

    return 0;
}

