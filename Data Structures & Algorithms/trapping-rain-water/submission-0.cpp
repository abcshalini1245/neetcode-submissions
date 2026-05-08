class Solution {
public:
    int trap(vector<int>& height) {
        
        int trap_water = 0;
        for(int i = 0; i<height.size(); i++){
            int mini = -1;
            int maxi =-1;
            for(int pre = 0; pre<i; pre++){
                 mini = max(height[pre], mini); 
            }
            for(int suff = i+1; suff<height.size(); suff++){
                 maxi = max(height[suff], maxi);
            }
            trap_water+=  max(0,min(mini,maxi)- height[i]);
 
        }
        return trap_water;
    }
};
