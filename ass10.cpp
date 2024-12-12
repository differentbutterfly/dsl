#include <iostream>
using namespace std;

// Custom Stack Implementation
class Stack {
private:
    char arr[1000]; // Array for stack elements
    int top;       // Top of the stack

public:
    Stack() { top = -1; } // Constructor initializes top to -1

    void push(char ch) {
        if (top >= 999) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = ch;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        top--;
    }

    char peek() {
        if (top == -1) {
            return '\0'; // Return null character if stack is empty
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to check if the given expression is well-parenthesized
bool isWellParenthesized(const string& expression) {
    Stack s;

    // Traverse each character of the expression
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            // Push opening delimiters onto the stack
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            // Check if the stack is empty or top does not match
            if (s.isEmpty() || 
                (ch == ')' && s.peek() != '(') ||
                (ch == '}' && s.peek() != '{') ||
                (ch == ']' && s.peek() != '[')) {
                return false;
            }
            s.pop(); // Pop the matched opening delimiter
        }
    }

    // If the stack is empty, the expression is well-parenthesized
    return s.isEmpty();
}

int main() {
    int choice;
    string expression;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Check Expression" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "\nEnter an expression: ";
                cin >> expression;

                if (isWellParenthesized(expression)) {
                    cout << "The expression is well parenthesized." << endl;
                } else {
                    cout << "The expression is NOT well parenthesized." << endl;
                }
                break;

            case 2:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 2);

    return 0;
}
