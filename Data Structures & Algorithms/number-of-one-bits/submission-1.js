class Solution {
    /**
     * @param {number} n - a positive integer
     * @return {number}
     */
    hammingWeight(n) {
        let cnt = 0;
       while(n!=0){
        let bit = n&1;
        if(bit == 1)
          cnt++;
        n = n>>1;
       }
       return cnt;
        
    }
}
