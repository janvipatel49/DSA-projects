#include <iostream>
using namespace std;

class Stack {
private:
    int arr[5];   // array to hold elements (fixed size)
    int top;      // index of top element
    int size;     // max size of stack

public:
    // Constructor
    Stack() {
        size = 5;
        top = -1; // stack is empty initially
    }

    // Push method
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    // Pop method
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    // Display top element
    void topElement() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element." << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == size - 1;
    }
};

// Main function
int main() {
    Stack s;   // create stack object
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display Top\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.topElement();
            break;
        case 4:
            if (s.isEmpty())
                cout << "Stack is Empty." << endl;
            else
                cout << "Stack is NOT Empty." << endl;
            break;
        case 5:
            if (s.isFull())
                cout << "Stack is Full." << endl;
            else
                cout << "Stack is NOT Full." << endl;
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

