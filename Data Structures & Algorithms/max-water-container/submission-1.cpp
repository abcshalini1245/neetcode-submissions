// class Solution {
// public:
//     int maxArea(vector<int>& heights) {
//         int maxarea = -1;
//         for(int i = 0; i<heights.size(); i++){
//             for(int j = i+1; j<heights.size(); j++){
//                 int area = min( heights[i],heights[j]) * abs(i-j);
//                 maxarea = max(maxarea,area);
//             }
//         }
//        return maxarea; 
//     }
// };


class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea = -1;
        int left = 0;
        int right = heights.size()-1;
        while(left<right){
            int area = min(heights[left],heights[right])* abs(left-right);
            maxarea = max(area,maxarea);
            if(heights[left]<heights[right])
                left++;
            else
               right--;
            
        }

       return maxarea; 
    }
};

