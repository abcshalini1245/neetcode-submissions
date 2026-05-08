class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //map is intially empty and it will store like value->index
        map<int,int>mp;
        for(int i =0; i<nums.size(); i++){
            int diff = target-nums[i];
            if(mp.find(diff) != mp.end()){
                return {mp[diff], i};
            }
            mp[nums[i]] = i; // we have to do it to fill the map table with their respected index

        }
        return {};
         

        }
        
        
    
};
