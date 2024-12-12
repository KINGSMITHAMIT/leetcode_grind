class MyQueue {
public:
    stack<int> st;
    stack<int> s;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(st.size()>0){
            s.push(st.top());
            st.pop();
        }
        int x = s.top();
        s.pop();
        while(s.size()>0){
            st.push(s.top());
            s.pop();
        }
        return x;
    }       
    
    int peek() {
        while(st.size()>0){
            s.push(st.top());
            st.pop();
        }
        int x = s.top();
        while(s.size()>0){
            st.push(s.top());
            s.pop();
        }
        return x;
    }
    
    bool empty() {
        if(st.size() == 0) return 1;
        return 0;
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