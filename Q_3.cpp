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

bool check(string str){
    Stack left,right;
    for(int i = 0; i<str.length();i++){
        if(str[i]=='('){
            left.push(str[i]);
        }
        else if(str[i]==')'){
            right.push(str[i]);
        }
    }
    if (left.top == right.top){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    string expression = "2*(3+4)-6=8)";
    if(check(expression)){
        cout<<"Balanced Parenthesis";
    }
    else{
        cout<<"Unbalanced Parenthesis";
    }
    return 0;
}
