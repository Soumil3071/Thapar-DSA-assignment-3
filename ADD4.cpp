#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temp) {
    int n=temp.size();
    vector<int> res(n,0);
    stack<int> st;
    for (int i=0;i<n;i++) {
        while (!st.empty() && temp[i]>temp[st.top()]) {
            int idx=st.top(); st.pop();
            res[idx]=i-idx;
        }
        st.push(i);
    }
    return res;
}

int main() {
    vector<int> temp = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(temp);
    cout<<"Days to wait: ";
    for (int x: ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}
