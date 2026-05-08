class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      vector<int>result;
      for(int i = 0; i<temperatures.size(); i++){
        bool found = false;
         for(int j = i+1; j<temperatures.size(); j++){
            if(temperatures[j] > temperatures[i]){
                int ans = j-i;
                found = true;
                result.push_back(ans);
                break;
            }

          
         }
       if(!found)
        result.push_back(0);
      }
      return result;  
    }
};
