//question5 5. Write a top down parser for the following grammar:

//E :: = T{ +T }
//
//T :: = F{ *F }
//
//F :: = num | id
//
//Where : “ + ” is the addition operator,
//
//“ * ” is the multiplication operator


#include <iostream>
#include <string>

//header file declares a set of functions to classify (and transform) individual characters.
#include <cctype>

using namespace std;

// Function declarations

void E();   //Expression
void T();   //term
void F();   //factor

//cheah if the term is match or not
void match(char expectedToken);
char currentToken();
bool isEnd();

// Global variables
string input;
int currentPosition = 0;

char currentToken() {
    if (isEnd()) {
        return '\0'; // Return null character if we are at the end
    }
    return input[currentPosition];
}

void match(char expectedToken) {
    if (currentToken() == expectedToken) {
        currentPosition++;
    }
    else {
        cerr << "Error: Expected '" << expectedToken << "' but found '" << currentToken() << "'." << endl;
        exit(1); // Exit on error
    }
}

bool isEnd() {
    return currentPosition >= input.length();
}

void E() {
    cout << "Parsing E -> T" << endl;
    T();
    while (currentToken() == '+') {
        cout << "Parsing E -> E + T" << endl;
        match('+');
        T();
    }
}

void T() {
    cout << "Parsing T -> F" << endl;
    F();
    while (currentToken() == '*') {
        cout << "Parsing T -> T * F" << endl;
        match('*');
        F();
    }
}

void F() {
    if (isdigit(currentToken())) {
        cout << "Parsing F -> num" << endl;
        while (isdigit(currentToken())) {
            match(currentToken()); // Consume the number
        }
    }
    else if (isalpha(currentToken())) {
        cout << "Parsing F -> id" << endl;
        while (isalpha(currentToken())) {
            match(currentToken()); // Consume the identifier
        }
    }
    else {
        cerr << "Error: Expected num or id, found '" << currentToken() << "'." << endl;
        exit(1); // Exit on error
    }
}

int main() {
    cout << "Enter an arithmetic expression: ";
    getline(cin, input); // Read the entire line as input

    E(); // Start parsing from the non-terminal E

    if (isEnd()) {
        cout << "Parsing successful!" << endl;
    }
    else {
        cerr << "Error: Unexpected characters at the end." << endl;
    }

    return 0;
}
