/*
232. Implement Queue using Stacks

Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, 
peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a 
stack by using a list or deque (double-ended queue), as long as you use only standard 
operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations 
will be called on an empty queue).
*/
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2; 
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = peek();
        if(!s2.empty()){
            s2.pop();
        }
        return top;        
    }
    
    /** Get the front element. */
    int peek() {
        int front;
        if(s2.empty() && s1.empty()){
            return -1;
        }        
        else if(s2.empty()){
            while(!s1.empty()){
                int t = s1.top();
                s1.pop();
                s2.push(t);
            }
            front = s2.top();
        }
        else{
            front = s2.top();
        }
        return front;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (s1.empty() && s2.empty());        
    }
};

class MyQueue {
private:
    stack<int> m_s;
private:
    void helper(int x){
        if(m_s.empty()){
            m_s.push(x);
            return;
        }
        
        int top = m_s.top();
        m_s.pop();
        helper(x);
        m_s.push(top);
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        helper(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = m_s.top();
        m_s.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        return m_s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return m_s.empty();        
    }
};