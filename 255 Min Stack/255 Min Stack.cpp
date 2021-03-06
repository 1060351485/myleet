//
//  255 Min Stack.cpp
//  
//
//  Created by Apple on 15/7/15.
//
//

class MinStack {
public:
    stack<int> Sin,min;
    void push(int x) {
        int tempMin = min.size()?getMin():x;
        Sin.push(x);
        if( tempMin <= x )
            min.push(tempMin);
        else
            min.push(x);
    }
    
    void pop() {
        // if( Sin.top() == min.top() )
        min.pop();
        Sin.pop();
    }
    
    int top() {
        return Sin.top();
    }
    
    int getMin() {
        return min.top();
    }
};