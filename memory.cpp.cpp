#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;

    Student(int id, string name) {
        this->id = id;
        this->name = name;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

void addStudent(vector<Student>& students) {
    int id;
    string name;
    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Student Name: ";
    cin >> name;
    students.push_back(Student(id, name));
    cout << "student added successfully.\n";
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to display.\n";
        return;
    }

    cout << "?? Student List:\n";
    for (const Student& s : students) {
        s.display();
    }
}

void removeStudentByID(vector<Student>& students) {
    int id;
    cout << "Enter ID to remove: ";
    cin >> id;

    bool found = false;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "? Student removed successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "student with ID " << id << " not found.\n";
    }
}

void searchStudentByID(const vector<Student>& students) {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    bool found = false;
    for (const Student& s : students) {
        if (s.id == id) {
            cout << " Student Found: ";
            s.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "student with ID " << id << " not found.\n";
    }
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n========= Student Management Menu =========\n";
        cout << "1. Add a Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove a Student by ID\n";
        cout << "4. Search for a Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                removeStudentByID(students);
                break;
            case 4:
                searchStudentByID(students);
                break;
            case 5:
                cout << " Exiting the program.\n";
                break;
            default:
                cout << "invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

