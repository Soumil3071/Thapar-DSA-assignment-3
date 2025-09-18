#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr) {
    stack<char> st;
    for (char c: expr) {
        if (c=='('||c=='{'||c=='[') st.push(c);
        else if (c==')'||c=='}'||c==']') {
            if (st.empty()) return false;
            char t = st.top(); st.pop();
            if ((c==')'&&t!='(')||(c=='}'&&t!='{')||(c==']'&&t!='[')) return false;
        }
    }
    return st.empty();
}

int main() {
    string expr1 = "{[()]}";
    string expr2 = "{[(])}";
    cout << expr1 << " -> " << (isBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;
    cout << expr2 << " -> " << (isBalanced(expr2) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
