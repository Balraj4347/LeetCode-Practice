class MyQueue {
       stack<int> push_stack;
        stack<int> pop_stack;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(!pop_stack.empty())
            while(!pop_stack.empty())
            {push_stack.push( pop_stack.top() );
            pop_stack.pop();}
        push_stack.push(x);
        
    }
    
    int pop() {
        if(!push_stack.empty())
            while(!push_stack.empty())
            {
                pop_stack.push( push_stack.top() );
                push_stack.pop();
            }
        int temp= pop_stack.top();
        pop_stack.pop();
        return temp;        
    }
    
    int peek() {
        if(!push_stack.empty())
            while(!push_stack.empty())
            {
                pop_stack.push( push_stack.top() );
                push_stack.pop();
            }
     
        return pop_stack.top();  
    }
    
    bool empty() {
        
        return push_stack.empty() && pop_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
