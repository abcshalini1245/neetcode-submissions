// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//       vector<int>result;
//       for(int i = 0; i<temperatures.size(); i++){
//         bool found = false;
//          for(int j = i+1; j<temperatures.size(); j++){
//             if(temperatures[j] > temperatures[i]){
//                 int ans = j-i;
//                 found = true;
//                 result.push_back(ans);
//                 break;
//             }

          
//          }
//        if(!found)
//         result.push_back(0);
//       }
//       return result;  
//     }
// };




class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;  // will store indices
        
        for(int i = n - 1; i >= 0; i--) {
            
            // Pop all smaller or equal temperatures
            while(!st.empty() && 
                  temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            
            // If stack not empty, calculate distance
            if(!st.empty()) {
                result[i] = st.top() - i;
            }
            
            // Push current index
            st.push(i);
        }
        
        return result;
    }
};

