class MyStack {
public:
    queue<int> st;
    MyStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        for(int i = 1; i < st.size(); i++){
            st.push(st.front());
            st.pop();
        }
    }
    
    int pop() {
        int temp = st.front();
        st.pop();
        return temp;
    }
    
    int top() {
        return st.front();
    }
    
    bool empty() {
        if(st.size() == 0) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */