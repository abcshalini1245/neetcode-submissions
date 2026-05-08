class Solution {
private:
        int get_pivot(vector<int>& nums){
        int s =0; int e = nums.size() -1;
        while(s<e){
            int mid = s + (e-s)/2;
            if(nums[mid]>nums[e])
               s = mid+1;
            else
              e = mid;
        }
        return s;
    }
       int binary_search(vector<int>& nums, int s,int e,int target){
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]== target)
               return mid;
            else if(target<nums[mid])
              e = mid-1;
            else
              s = mid+1;
               
        }
        return -1;
       }
public:
    int search(vector<int>& nums, int target) {
        int min_element = get_pivot(nums);
        if(target>= nums[min_element] && target<= nums[nums.size()-1])
          return binary_search(nums,min_element,nums.size()-1,target);
        else
          return binary_search(nums,0,min_element-1,target);
    }
};
