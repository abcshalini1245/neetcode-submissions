class Solution {
private:
  vector<int>merge(vector<int>& nums1, vector<int>& nums2){
    int n = nums1.size();
    int m = nums2.size();
    vector<int>nums3(n+m);
    int i =0, j=0, k=0;
    while(i<n && j<m){
        if(nums1[i]<=nums2[j]){
           nums3[k]=nums1[i];
           k++,i++;
        }
        else{
           nums3[k] = nums2[j];
          k++, j++;
        }
    }
    while(i<n){
        nums3[k]=nums1[i];
        k++,i++;
    }
    while(j<m){
        nums3[k]=nums2[j];
        k++,j++;
    }
    return nums3;
  }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     vector<int>nums=  merge(nums1,nums2);
     if(nums.size() & 1){
         double median = nums[nums.size()/2];
         return median;
     }
     else{
         
        double median = (nums[nums.size()/2] + nums[(nums.size()/2)-1])/2.0;
        return median;
     }

    }
};
