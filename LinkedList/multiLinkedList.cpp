#include <iostream>
#include <string>
using namespace std;

// Node structure for the number list
struct NumberNode {
    int number;
    NumberNode* next;

    NumberNode(int num) : number(num), next(nullptr) {}
};

// Node structure for the student list
struct StudentNode {
    string name;
    NumberNode* numberHead;  // Head of the number linked list
    StudentNode* next;       // Next student in the list

    StudentNode(string n) : name(n), numberHead(nullptr), next(nullptr) {}
};

// Function to add a number to a student's number list
void addNumberToStudent(StudentNode* student, int num) {
    NumberNode* newNumber = new NumberNode(num);
    if (student->numberHead == nullptr) {
        student->numberHead = newNumber;
    } else {
        NumberNode* current = student->numberHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNumber;
    }
}

// Function to add a student to the list
void addStudent(StudentNode*& head, string name) {
    StudentNode* newStudent = new StudentNode(name);
    if (head == nullptr) {
        head = newStudent;
    } else {
        StudentNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newStudent;
    }
}

// Function to display all students and their numbers
void displayStudents(StudentNode* head) {
    StudentNode* currentStudent = head;
    while (currentStudent != nullptr) {
        cout << "Student: " << currentStudent->name << endl;
        cout << "Numbers: ";
        
        NumberNode* currentNumber = currentStudent->numberHead;
        while (currentNumber != nullptr) {
            cout << currentNumber->number << " -> ";
            currentNumber = currentNumber->next;
        }
        cout << "NULL" << endl << endl;
        
        currentStudent = currentStudent->next;
    }
}

// Function to delete all allocated memory
void deleteAll(StudentNode*& head) {
    StudentNode* currentStudent = head;
    while (currentStudent != nullptr) {
        // Delete numbers first
        NumberNode* currentNumber = currentStudent->numberHead;
        while (currentNumber != nullptr) {
            NumberNode* temp = currentNumber;
            currentNumber = currentNumber->next;
            delete temp;
        }
        
        // Delete student node
        StudentNode* temp = currentStudent;
        currentStudent = currentStudent->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    StudentNode* head = nullptr;

    // Add students
    addStudent(head, "Alice");
    addStudent(head, "Bob");
    addStudent(head, "Charlie");

    // Add numbers to students
    StudentNode* current = head;
    addNumberToStudent(current, 1001);  // Add to Alice
    addNumberToStudent(current, 1002);
    
    current = current->next;  // Move to Bob
    addNumberToStudent(current, 2001);
    
    current = current->next;  // Move to Charlie
    addNumberToStudent(current, 3001);
    addNumberToStudent(current, 3002);
    addNumberToStudent(current, 3003);

    // Display the nested lists
    displayStudents(head);

    // Clean up memory
    deleteAll(head);

    return 0;
}