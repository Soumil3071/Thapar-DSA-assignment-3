#include <iostream>
#include <stack>
using namespace std;

string reverseString(string s) {
    stack<char> st;
    for (char c: s) st.push(c);
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int main() {
    string s = "DataStructure";
    cout << "Original: " << s << endl;
    cout << "Reversed: " << reverseString(s) << endl;
    return 0;
}
