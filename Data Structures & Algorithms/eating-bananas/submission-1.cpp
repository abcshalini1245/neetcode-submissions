class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi =0;
        int ans =-1;
        for(int i =0; i<piles.size(); i++){
            maxi = max(maxi,piles[i]);
        }
        int s =1; 
        int e =maxi; 
       
        while(s<=e){
            int mid = s + (e-s)/2;
             int time =0;

            for(int i =0; i<piles.size(); i++){
                //Use (a + b - 1) / b for ceil division
               time+= (piles[i]+mid-1)/mid;
              // time+= ceil((double)piles[i]/mid);
            }
            if(time<=h){
                ans = mid;
                e = mid-1;
            }
            else{
               s = mid+1; 
            }
        }
        return ans;
    }
};
