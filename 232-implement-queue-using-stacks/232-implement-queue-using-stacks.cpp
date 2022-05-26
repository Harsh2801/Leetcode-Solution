class MyQueue {
public:
    stack<int> temp;
    stack<int> ans_q;
    MyQueue() {
        
    }
    
    void push(int x) {
        int n=ans_q.size();
        for(int i=0;i<n;i++){
            temp.push(ans_q.top());
            ans_q.pop();
        }
        ans_q.push(x);
        for(int i=0;i<n;i++){
            ans_q.push(temp.top());
            temp.pop();
        }
    }
    
    int pop() {
        int ans=ans_q.top();
        ans_q.pop();
        return ans;
    }
    
    int peek() {
        return ans_q.top();
    }
    
    bool empty() {
        if(ans_q.size()==0) return true;
        return false;
    }
};