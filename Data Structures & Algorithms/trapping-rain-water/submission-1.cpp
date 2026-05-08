// class Solution {
// public:
//     int trap(vector<int>& height) {
        
//         int trap_water = 0;
//         for(int i = 0; i<height.size(); i++){
//             int mini = -1;
//             int maxi =-1;
//             for(int pre = 0; pre<i; pre++){
//                  mini = max(height[pre], mini); 
//             }
//             for(int suff = i+1; suff<height.size(); suff++){
//                  maxi = max(height[suff], maxi);
//             }

//             //trap water can not be negative so we use 0
//             trap_water+=  max(0,min(mini,maxi)- height[i]);
 
//         }
//         return trap_water;
//     }
// };

// class Solution {
// public:
//     int trap(vector<int>& height) {
        
//         int trap_water = 0;
//         for(int i = 0; i<height.size(); i++){
//             int mini = -1;
//             int maxi =-1;
//             for(int pre = 0; pre<i; pre++){
//                  mini = max(height[pre], mini); 
//             }
//             for(int suff = i+1; suff<height.size(); suff++){
//                  maxi = max(height[suff], maxi);
//             }

//             //trap water can not be negative so we use 0
//             trap_water+=  max(0,min(mini,maxi)- height[i]);
 
//         }
//         return trap_water;
//     }
// };

// class Solution {
// public:
//     int trap(vector<int>& nums) {
//         int n = nums.size();
//         int trap_water = 0;
//         vector<int>prefix(nums.size());
//         prefix[0] = nums[0];
//         for(int i = 1; i<nums.size();i++){
//             prefix[i] = max(prefix[i-1],nums[i]);
//         }
//         vector<int>suffix(nums.size());
//         suffix[n-1] = nums[n-1];
//         for(int i = n-2; i>=0;i--){
//             suffix[i] = max(suffix[i+1],nums[i]);
//         }  
//         for(int i=1; i<n-1; i++){
//             trap_water+= max(0,min(prefix[i-1],suffix[i+1]) - nums[i]);
//         }
//         return trap_water;
//     }
// };


class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                leftMax = max(leftMax, height[l]);
                water += leftMax - height[l];
                l++;
            } else {
                rightMax = max(rightMax, height[r]);
                water += rightMax - height[r];
                r--;
            }
        }
        return water;
    }
};


