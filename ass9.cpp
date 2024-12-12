#include<iostream>
#define MAX_SIZE 50 // Maximum size of the stack
using namespace std;

// Class to simulate stack operations for character arrays
class Stack {
    private:
        char elements[MAX_SIZE]; // Array to store stack elements
        int topIndex;            // Index to keep track of the top of the stack

    public:
        // Constructor to initialize stack
        Stack() {
            topIndex = -1;	
        }	

        void push(char character);     // Method to push a character onto the stack
        void reverseString();          // Method to reverse and display the string
        void processString(char[]);    // Method to convert input string to lowercase and remove non-alphabetic characters
        void checkPalindrome();        // Method to check if the string is a palindrome
        void clearStack();             // Method to clear the stack
};

// Method to push a character onto the stack
void Stack::push(char character) {
    if (topIndex < MAX_SIZE - 1) { // Ensure stack does not overflow
        topIndex++;
        elements[topIndex] = character;
        elements[topIndex + 1] = '\0'; // Null-terminate the string
    } else {
        cout << "Stack overflow, cannot add more characters.\n";
    }
}

// Method to reverse and display the string stored in the stack
void Stack::reverseString() {
    if (topIndex == -1) {
        cout << "\nStack is empty, nothing to reverse.\n";
        return;
    }

    char reversed[MAX_SIZE]; // Temporary array to store reversed string

    cout << "\nReversed string is: ";
    for (int i = topIndex, j = 0; i >= 0; i--, j++) {
        cout << elements[i];   // Print characters in reverse order
        reversed[j] = elements[i]; // Store the reversed string
    }
    cout << endl;
}

// Method to convert input string to lowercase and remove non-alphabetic characters
void Stack::processString(char input[]) {
    int originalIndex = 0, processedIndex = 0;

    for (originalIndex = 0; input[originalIndex] != '\0'; originalIndex++) {
        // Check if the character is alphabetic
        if ((input[originalIndex] >= 'a' && input[originalIndex] <= 'z') || 
            (input[originalIndex] >= 'A' && input[originalIndex] <= 'Z')) {

            // Convert uppercase to lowercase
            if (input[originalIndex] >= 'A' && input[originalIndex] <= 'Z') {
                input[processedIndex] = input[originalIndex] + 32;
            } else {
                input[processedIndex] = input[originalIndex];
            }
            processedIndex++;
        }
    }
    input[processedIndex] = '\0'; // Null-terminate the processed string
    cout << "\nProcessed string: " << input << "\n";
}

// Method to check if the string is a palindrome
void Stack::checkPalindrome() {	
    if (topIndex == -1) {
        cout << "\nStack is empty, cannot check for palindrome.\n";
        return;
    }

    char reversed[MAX_SIZE]; // Array to store reversed string
    int i, j;		

    for (i = topIndex, j = 0; i >= 0; i--, j++) {
        reversed[j] = elements[i]; // Reverse the stack contents
    }
    reversed[j] = '\0'; // Null-terminate the reversed string
	
    // Compare reversed string with the original string in the stack
    bool isPalindrome = true;
    for (i = 0; i <= topIndex; i++) {
        if (elements[i] != reversed[i]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "\nThe string is a palindrome.\n";
    } else {
        cout << "\nThe string is not a palindrome.\n";
    }
}

// Method to clear the stack
void Stack::clearStack() {
    topIndex = -1;
    cout << "\nStack has been cleared.\n";
}

// Main function
int main() {
    Stack stack; // Create a Stack object
    char inputString[MAX_SIZE];
    int choice;

    do {
        // Display menu options
        cout << "\nMenu:\n";
        cout << "1. Enter a new string\n";
        cout << "2. Check if the string is a palindrome\n";
        cout << "3. Reverse the string\n";
        cout << "4. Clear the stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1:
                cout << "\nEnter a string: ";
                cin.getline(inputString, MAX_SIZE);
                stack.processString(inputString);

                // Push characters of the processed string onto the stack
                for (int i = 0; inputString[i] != '\0'; i++) {
                    stack.push(inputString[i]);
                }
                break;

            case 2:
                stack.checkPalindrome();
                break;

            case 3:
                stack.reverseString();
                break;

            case 4:
                stack.clearStack();
                break;

            case 5:
                cout << "\nExiting program.\n";
                break;

            default:
                cout << "\nInvalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
