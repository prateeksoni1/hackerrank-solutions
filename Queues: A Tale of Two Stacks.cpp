#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack1, stack2;   
        void push(int x) {
            stack1.push(x);               
        }

        void pop() {

            if (stack2.empty()) {
                while(!stack1.empty()) {
                    int p = stack1.top();
                    stack1.pop();
                    stack2.push(p);
                }
            }
            stack2.pop();
        }

        int front() {
            if (stack2.empty()) {
               while(!stack1.empty()) {
                    int p = stack1.top();
                    stack1.pop();
                    stack2.push(p);
                } 
            }
            return stack2.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}