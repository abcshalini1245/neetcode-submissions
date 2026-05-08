class Solution {
public:
    int getSum(int a, int b) {
        //“XOR gives sum without carry, AND gives carry; repeat until carry becomes zero.”
        //But carry must move one position left: carry<<1
//         XOR → sum
//        AND → carry
//        SHIFT → position
//        REPEAT → until no carry
      while(b!= 0){
        int sum = a^b;
        int carry = (a&b)<<1;
        a = sum;
        b = carry;
      }
     return a;
    }
};
