#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool canStackSort(vector<int>& A) {
    stack<int> st;
    vector<int> B;
    for (int x:A) {
        st.push(x);
        while (!st.empty() && (B.empty()||st.top()>=B.back())) {
            B.push_back(st.top());
            st.pop();
        }
    }
    for (int i=1;i<B.size();i++) if (B[i]<B[i-1]) return false;
    return true;
}

int main() {
    vector<int> A = {1, 2, 3};
    cout<<(canStackSort(A)?"Yes":"No")<<endl;
    vector<int> B = {3, 1, 2};
    cout<<(canStackSort(B)?"Yes":"No")<<endl;
    return 0;
}
