#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stk;

    int totalElements, index, option, inputValue;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push elements\n";
        cout << "2. Pop element\n";
        cout << "3. Display top element\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Check if stack is full (simulated)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "How many values do you want to push onto the stack? ";
                cin >> totalElements;
                for (index = 0; index < totalElements; index++) {
                    cout << "Enter value " << index + 1 << ": ";
                    cin >> inputValue;
                    stk.push(inputValue);
                }
                break;

            case 2:
                if (!stk.empty()) {
                    cout << "Popped value from stack: " << stk.top();
                    stk.pop();
                } else {
                    cout << "Stack is empty";
                }
                break;

            case 3:
                if (!stk.empty()) {
                    cout << "Top value from stack: " << stk.top();
                } else {
                    cout << "Stack is empty";
                }
                break;

            case 4:
                if (stk.empty()) {
                    cout << "Stack is empty";
                } else {
                    cout << "Stack is not empty";
                }
                break;

            case 5:
                // Since the STL stack has no size limit, this is a simulated message.
                if (!stk.empty()) {
                    cout << "Stack is not full, but has elements.";
                } else {
                    cout << "Stack is empty, so not full.";
                }
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.";
        }

    } while (option != 0);

    // Display remaining elements in stack (if any)
    cout << "\nRemaining elements in stack (from top to bottom): ";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << "\n";

    return 0;
}
