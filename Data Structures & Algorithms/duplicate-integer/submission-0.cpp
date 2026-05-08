class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,bool>visited;
        
        for(int i = 0; i<nums.size(); i++){
            if(visited[nums[i]] == true)
               return true;
            visited[nums[i]] = true;

        }
        return false;
        

        
    }
};