class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //“I XOR all indices and values together; duplicate numbers cancel and the missing one remains.”
        int ans = nums.size();
        for( int i = 0; i<nums.size(); i++){
              ans = ans^i^nums[i];
        }
        return ans;
    }
};
