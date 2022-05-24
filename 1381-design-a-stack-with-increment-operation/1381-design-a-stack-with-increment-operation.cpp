class CustomStack {
public:
    stack<int> S1,S2;
    int maxi=0;
    CustomStack(int maxSize) {
        maxi=maxSize;
    }
    
    void push(int x) {
        if(S1.size()<maxi)
        S1.push(x);
    }
    
    int pop() {
        int x;
        if(!S1.empty()){
            x=S1.top();
            S1.pop();
            return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        while(k<S1.size()){
            S2.push(S1.top());
                S1.pop();
        }
        while(!S1.empty()){
            S2.push(S1.top()+val);
            S1.pop();
        }
        while(!S2.empty()){
            S1.push(S2.top());
            S2.pop();
        }
    }
};
