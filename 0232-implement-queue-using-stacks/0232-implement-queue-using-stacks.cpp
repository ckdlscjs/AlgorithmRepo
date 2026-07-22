auto fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

class MyQueue {
public:
    std::stack<int> st0, st1;
    MyQueue() {
        
    }
    
    void push(int x) 
    {
        st0.push(x);
    }
    
    int pop() {
        while(!st0.empty())
        {
            st1.push(st0.top());
            st0.pop();
        }
        int ret = st1.top();
        st1.pop();
        while(!st1.empty())
        {
            st0.push(st1.top());
            st1.pop();
        }
        return ret;
    }
    
    int peek() {
        while(!st0.empty())
        {
            st1.push(st0.top());
            st0.pop();
        }
        int ret = st1.top();
        while(!st1.empty())
        {
            st0.push(st1.top());
            st1.pop();
        }
        return ret;
    }
    
    bool empty() {
        return st0.empty();
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