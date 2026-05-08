class Solution {
public:
    int maxProfit(vector<int>& prices) {
//         Keep track of the minimum price seen so far
//         At each day, calculate:
//          profit = current price - min price so far
//          Update the maximum profit
      int min_price = INT_MAX;
      int max_profit = 0;
      for(int price: prices){
        min_price = min(min_price,price);
        max_profit = max(max_profit, price-min_price);
      }
      return max_profit;
        
    }
};
