#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreater(vector<int>& arr) {
    int n=arr.size();
    vector<int> res(n,-1);
    stack<int> st;
    for (int i=0;i<n;i++) {
        while (!st.empty() && arr[st.top()]<arr[i]) {
            res[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> ans = nextGreater(arr);
    cout<<"Next Greater Elements: ";
    for (int x: ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}
