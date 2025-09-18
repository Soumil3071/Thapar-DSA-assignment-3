#include <iostream>
#include <stack>
using namespace std;

int prec(char c) {
    if (c=='+'||c=='-') return 1;
    if (c=='*'||c=='/') return 2;
    if (c=='^') return 3;
    return 0;
}

string infixToPostfix(string expr) {
    stack<char> st;
    string res = "";
    for (char c: expr) {
        if (isalnum(c)) res += c;
        else if (c=='(') st.push(c);
        else if (c==')') {
            while (!st.empty() && st.top()!='(') {
                res += st.top(); st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(st.top())>=prec(c)) {
                res += st.top(); st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        res += st.top(); st.pop();
    }
    return res;
}

int main() {
    string expr;
    cout<<"Enter Infix Expression: ";
    cin>>expr;
    cout<<"Postfix: "<<infixToPostfix(expr)<<endl;
    return 0;
}
