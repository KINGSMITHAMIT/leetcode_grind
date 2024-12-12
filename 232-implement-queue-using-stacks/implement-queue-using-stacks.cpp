class MyQueue {
public:
    stack<int> st;
    stack<int> s;
    MyQueue() {
        
    }
    // 
    void push(int x) {
        if(st.size() == 0) st.push(x);
        else{
            while(st.size()!=0){
                s.push(st.top());
                st.pop();
            }
            st.push(x);
        }
            while(s.size()!=0){
                st.push(s.top());
                s.pop();
            }
    }
    
    int pop() {
        int x = st.top();
        st.pop();
        return x;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        if(st.size()==0) return 1;
        else return 0;
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