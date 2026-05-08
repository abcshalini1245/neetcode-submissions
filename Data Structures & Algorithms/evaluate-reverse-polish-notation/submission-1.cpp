class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
         int res;
        for(string ch: tokens){
            if(ch == "+" || ch =="-" || ch =="*" || ch == "/"){
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
               
                if(ch == "+")  res = num2+num1;
                if(ch == "-")  res = num2-num1;
                if(ch == "*")  res = num2*num1;
                if(ch == "/")  res = num2/num1;
                st.push(res);

            }
            else
               st.push(stoi(ch));
        }
      return st.top();  
    }
};
