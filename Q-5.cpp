#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100

class Stack {
public:
    int arr[MAX];
    int top;

    Stack() { top = -1; }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if (!isFull()) {
            arr[++top] = x;
        } else {
            cout << "OVERFLOW\n";
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            cout << "UNDERFLOW\n";
            return -1;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return -1;
    }
};

int evaluate_postfix(string expr) {
    Stack st;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        
        if (ch >= '0' && ch <= '9') {
            st.push(ch - '0'); 
        }
        else {
            int val2 = st.pop();
            int val1 = st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }

    return st.pop();
}

int main() {
    string postfix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    cout << "Evaluated Result: " << evaluate_postfix(postfix) << endl;

    return 0;
}
