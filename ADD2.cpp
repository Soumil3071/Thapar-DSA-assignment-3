#include <iostream>
using namespace std;

class MinStack {
    int *arr, *minArr, top, size;
public:
    MinStack(int n) {
        size=n; arr=new int[n]; minArr=new int[n]; top=-1;
    }
    void push(int x) {
        if (top<size-1) {
            arr[++top]=x;
            minArr[top] = (top==0)?x:min(x,minArr[top-1]);
        }
    }
    int pop() {
        if (top>=0) return arr[top--];
        return -1;
    }
    int getMin() {
        if (top>=0) return minArr[top];
        return -1;
    }
};

int main() {
    MinStack st(10);
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);
    cout<<"Current Min: "<<st.getMin()<<endl;
    st.pop();
    cout<<"After Pop, Min: "<<st.getMin()<<endl;
    return 0;
}
