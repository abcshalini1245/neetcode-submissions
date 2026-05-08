class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea = -1;
        for(int i = 0; i<heights.size(); i++){
            for(int j = i+1; j<heights.size(); j++){
                int area = min( heights[i],heights[j]) * abs(i-j);
                maxarea = max(maxarea,area);
            }
        }
       return maxarea; 
    }
};
