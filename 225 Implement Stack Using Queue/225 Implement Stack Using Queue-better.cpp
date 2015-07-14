//
//  225 Implement Stack Using Queue-better.cpp
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
    
    // reload data when push
    
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
        index = q1.size()-1;
        while(index--){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    // Removes the element on top of the stack.
    void pop() {
        if( q1.empty() )
            return;
        q1.pop();
    }
    
    // Get the top element.
    int top() {
        return q1.front();
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};