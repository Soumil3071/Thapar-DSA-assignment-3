#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nearestSmaller(vector<int>& arr) {
    vector<int> res(arr.size(), -1);
    stack<int> st;
    for (int i=0;i<arr.size();i++) {
        while (!st.empty() && st.top()>=arr[i]) st.pop();
        if (!st.empty()) res[i]=st.top();
        st.push(arr[i]);
    }
    return res;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = nearestSmaller(arr);
    cout<<"Nearest Smaller Elements: ";
    for (int x: ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}
