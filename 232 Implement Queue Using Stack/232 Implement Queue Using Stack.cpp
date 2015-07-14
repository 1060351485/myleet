//
//  232 Implement Queue Using Stack.cpp
//  
//
//  Created by Apple on 15/7/14.
//
//

class Queue {
public:
    
#include <stack>
    stack<int> S1, S2;
    int index;
    
    // Push element x to the back of queue.
    void push(int x) {
        while( !S1.empty() ){
            S2.push(S1.top());
            S1.pop();
        }
        S1.push(x);
        while( !S2.empty() ){
            S1.push(S2.top());
            S2.pop();
        }
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        S1.pop();
    }
    
    // Get the front element.
    int peek(void) {
        return S1.top();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return S1.empty();
    }
};