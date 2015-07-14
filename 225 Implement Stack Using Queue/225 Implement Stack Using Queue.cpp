//
//  225 Implement Stack Using Queue.cpp
//  
//
//  Created by Apple on 15/7/14.
//
//

class Stack {
public:
#include <queue>
    
    queue<int> q1;
    int index;
    
    // Push element x onto stack.
    // !! need to reload data when push and pop, slow
    void push(int x) {
        q1.push(x);
    }
    
    // Removes the element on top of the stack.
    void pop() {
        if( q1.empty() )
            return;
        index = q1.size()-1;
        while(index--){
            q1.push(q1.front());
            q1.pop();
        }
        q1.pop();
    }
    
    // Get the top element.
    int top() {
        if( q1.empty() )
            return NULL;
        index = q1.size()-1;
        while(index--){
            q1.push(q1.front());
            q1.pop();
        }
        int rslt = q1.front();
        q1.push(q1.front());
        q1.pop();
        return rslt;
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};