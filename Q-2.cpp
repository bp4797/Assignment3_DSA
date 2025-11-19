#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    public:

    char arr[MAX];
    int top;
    
    Stack() { top = -1; }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char c) {
        if (!isFull()) {
            arr[++top] = c;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
    }
};

string reverseString(string str) {
    Stack s;

    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    string reversed = "";
    while (!s.isEmpty()) {
        reversed += s.pop();
    }

    return reversed;
}

int main() {
    string input = "DataStructure";

    cout << "Original String: " << input << endl;
    string output = reverseString(input);
    cout << "Reversed String: " << output << endl;

    return 0;
}
