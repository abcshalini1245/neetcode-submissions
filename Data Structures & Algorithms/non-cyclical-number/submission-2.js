class Solution {
    /**
     * @param {number} n
     * @return {boolean}
     */
    isHappy(n) {
         let st = new Set();
        while(n!=1){
            if(st.has(n))
               return false;

           st.add(n);
           let ans = 0;
           while(n!=0){
            let digit = n%10;
            ans+= Math.pow(digit,2);
            n = Math.floor(n /10);
           }
           n = ans;
        }
        return true;
    }
}
