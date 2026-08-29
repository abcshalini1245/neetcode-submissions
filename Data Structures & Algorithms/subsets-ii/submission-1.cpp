class Solution {
private:
    void solve(vector<int>& nums, int index, vector<vector<int>>&output,         vector<int>&ans ){
       output.push_back(ans);
        for (int i = index; i < nums.size(); i++) {

            // Skip duplicate values at the same level
            if (i > index && nums[i] == nums[i - 1])
                continue;
     
       ans.push_back(nums[i]);
       solve(nums,i+1,output,ans);
       ans.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int index = 0;
         sort(nums.begin(), nums.end());
        vector<vector<int>>output;
        vector<int>ans;
        solve(nums,index,output,ans);
        // sort(output.begin(),output.end());
        // output.erase(unique(output.begin(),output.end()),output.end());
        return output;
    }
};
