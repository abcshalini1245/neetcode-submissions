class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        
        vector<int>ans(temperatures.size(),0);
        for(int i = temperatures.size()-1; i>=0; i-- ){
            int curr = temperatures[i];
            while(!st.empty() && temperatures[st.top()] <= curr){
                st.pop();
            }

            // If stack is not empty, calculate distance
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }

            // Store index
            st.push(i);
        }

        return ans;
    }
};
