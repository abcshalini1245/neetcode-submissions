class MinStack {
public:
    stack<pair<int,int>>s; //val,mini
    MinStack() {
      int mini = -1;
      int top = -1;  
    }
    
    void push(int val) {
        if(s.empty())
          s.push({val,val});
        else{
          int mini = min(val,s.top().second);
          s.push({val,mini});
        }
    }
    
    void pop() {
        if(!s.empty()){
          s.pop();
        }
    }
    
    int top() {
          if (!s.empty())
            return s.top().first;
          else
            return -1;
     }
    
    
    int getMin() {
        if (!s.empty())
          return s.top().second;
        else
          return -1;
    }
};
