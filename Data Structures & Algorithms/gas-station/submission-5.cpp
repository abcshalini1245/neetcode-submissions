class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_count = 0;
        int cost_count = 0;
        for(int i =0 ; i<gas.size(); i++){
            gas_count += gas[i];
            cost_count +=cost[i];
        }
        if(gas_count < cost_count )
          return -1;
        int sol = 0;
        int start = 0;
        for(int i = 0; i< gas.size(); i++){
             
            sol = sol+ gas[i] - cost[i];
            if(sol < 0){
                start = i+1;
              sol = 0;
            }
            
        }
        return start;
    }
};
