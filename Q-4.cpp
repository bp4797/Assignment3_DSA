#include <iostream>
using namespace std;
#define MAX 100

class Stack {
public:
    int top;
    char arr[MAX];

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
            cout << "OVERFLOW\n";
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            cout << "UNDERFLOW\n";
            return '\0';
        }
    }

    char peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0';
    }
};

int priority(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string convert(string str) {
    string ans = "";
    Stack temp;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9')) {
            ans += ch;
        }
        else if (ch == '(') {
            temp.push(ch);
        }
        else if (ch == ')') {
            while (!temp.isEmpty() && temp.peek() != '(') {
                ans += temp.pop();
            }
            if (!temp.isEmpty() && temp.peek() == '(') {
                temp.pop();
            }
        }
        else {
            while (!temp.isEmpty() && priority(ch) <= priority(temp.peek())) {
                ans += temp.pop();
            }
            temp.push(ch);
        }
    }

    while (!temp.isEmpty()) {
        ans += temp.pop();
    }

    return ans;
}

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    cout << "Postfix Expression: " << convert(infix) << endl;
    return 0;
}
