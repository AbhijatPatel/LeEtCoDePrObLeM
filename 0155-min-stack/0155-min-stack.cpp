class MinStack {
public:
stack<long long> st;
long long minVal;

    MinStack() {
        
    }
    
    void push(long long value) {
        if(st.empty()){
            st.push(value);
            minVal = value;
        }
        else if(value >= minVal){
            st.push(value);
        }
        else{
            st.push(2 * value - minVal);
            minVal = value;
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
            long long value = st.top();
            st.pop();

            if(value < minVal){
                minVal = 2 * minVal - value;
            }
        }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        long long value = st.top();
        if(value < minVal){
            return minVal;
        }
        return value;
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * long long param_3 = obj->top();
 * long long param_4 = obj->getMin();
 */