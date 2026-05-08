class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //prefix and suffix approach
        //calculate prefix
        vector<int>ans(nums.size());
        int n = nums.size();
        vector<int>prefix(nums.size());
        prefix[0] = 1;
        for(int i = 1; i<nums.size();i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        vector<int>suffix(nums.size());
        suffix[n-1] = 1;
        for(int i = n-2; i>=0;i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        for(int i = 0 ; i<nums.size(); i++){
            ans[i] = prefix[i]*suffix[i];
        }
     return ans;
       
    }
};



// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//          vector<int>ans(nums.size(), 1);
//         for(int i = 0; i<nums.size();i++){
//           for(int j = 0; j < nums.size(); j++){
//             if (i == j) continue;
//             ans[i] = ans[i] * nums[j];
//           }
             
//         }
//     return ans;
//     }
// };
