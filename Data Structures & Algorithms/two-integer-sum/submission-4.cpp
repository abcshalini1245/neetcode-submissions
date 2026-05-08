// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         //map is intially empty and it will store like value->index
//         map<int,int>mp;
//         for(int i =0; i<nums.size(); i++){
//             int diff = target-nums[i];
//             if(mp.find(diff) != mp.end()){
//                 return {mp[diff], i}
//             }
//             mp[nums[i]] = i; // we have to do it to fill the map table with their respected index

//         }
//         return {};
         

//         }
        
        
    
// };


//two pointer approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     vector<pair<int,int>> arr;
     //restore original indexes
     for (int i = 0; i < nums.size(); i++) {
          arr.push_back({nums[i], i});
       }

        sort(arr.begin(), arr.end());
        
        int left = 0; 
        int right = arr.size()-1;
        while(left<right){
            if(arr[left].first + arr[right].first == target){
              
                //it will give original index only that we stored earlier()
                int i1 = arr[left].second;
                int i2 = arr[right].second;

                if (i1 > i2) swap(i1, i2);

                return {i1, i2};

               
          
            }

            else if(arr[left].first + arr[right].first < target)
                left++;

            else
              right--;
        }

       return {};
    }
};
