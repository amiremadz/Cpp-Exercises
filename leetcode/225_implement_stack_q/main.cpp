/*
225. Implement Stack using Queues

Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, 
peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a 
queue by using a list or deque (double-ended queue), as long as you use only standard 
operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations 
will be called on an empty stack).
*/
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

class MyStack {
private:
    queue<int> m_q1;
    queue<int> m_q2;
    int m_top;
    
public:
    /** Initialize your data structure here. */
    MyStack() {        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        m_q1.push(x);
        m_top = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int front;
        while(m_q1.size() > 1){
            front = m_q1.front();
            m_q2.push(front);
            m_q1.pop();
        }        
        m_top = front;
        front = m_q1.front();
        m_q1.pop();
        
        queue<int> tmp = m_q1;
        m_q1 = m_q2;
        m_q2 = tmp;        
        
        return front;
    }
    
    /** Get the top element. */
    int top() {
        return m_top;        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return(m_q1.empty());
    }
};

/*
    push 1 -> [1]       and no rotate
    push 2 -> [2,1]     and rotate 1 time : -> [1,2]
    push 3 -> [2,1,3]   and rotate 2 times: -> [1,3,2] -> [3,2,1]
    push 4 -> [3,2,1,4] and rotate 3 times: -> [2,1,4,3] -> [1,4,3,2] -> [4,3,2,1]
    pop    -> [3,2,1]   and return 4
    pop    -> [2,1]     and return 3
    push 5 -> [2,1,5]   and rotate 2 times: -> [1,5,2] -> [5,2,1]
    pop    -> [2,1]     and return 5
    */

class MyStack {
private:
    queue<int> m_q;
    
public:
    /** Initialize your data structure here. */
    MyStack() {        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        m_q.push(x);
        for(int i = 0; i < m_q.size() - 1; ++i){
            m_q.push(m_q.front());
            m_q.pop();
        }
    }
   
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = m_q.front();
        m_q.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return m_q.front();        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return(m_q.empty());
    }
};