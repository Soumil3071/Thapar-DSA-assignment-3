#include <iostream>
using namespace std;

class Stack {
    int *arr, top, size;
public:
    Stack(int n) {
        size=n;
        arr=new int[n];
        top=-1;
    }
    void push(int x) {
        if (top<size-1) arr[++top]=x;
        else cout<<"Stack Overflow\n";
    }
    void pop() {
        if (top>=0) cout<<"Popped: "<<arr[top--]<<endl;
        else cout<<"Stack Underflow\n";
    }
    void peek() {
        if (top>=0) cout<<"Top: "<<arr[top]<<endl;
        else cout<<"Stack Empty\n";
    }
    void isEmpty() {
        cout<<(top==-1?"Stack is Empty":"Stack is not Empty")<<endl;
    }
    void isFull() {
        cout<<(top==size-1?"Stack is Full":"Stack is not Full")<<endl;
    }
    void display() {
        if (top==-1) cout<<"Stack Empty\n";
        else {
            cout<<"Stack: ";
            for (int i=0;i<=top;i++) cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
};

int main() {
    int n, choice, val;
    cout<<"Enter stack size: "; cin>>n;
    Stack s(n);
    do {
        cout<<"\n1.Push 2.Pop 3.Peek 4.isEmpty 5.isFull 6.Display 7.Exit\n";
        cout<<"Enter choice: "; cin>>choice;
        switch(choice) {
            case 1: cout<<"Enter value: "; cin>>val; s.push(val); break;
            case 2: s.pop(); break;
            case 3: s.peek(); break;
            case 4: s.isEmpty(); break;
            case 5: s.isFull(); break;
            case 6: s.display(); break;
        }
    } while(choice!=7);
    return 0;
}
