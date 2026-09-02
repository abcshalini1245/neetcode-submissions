class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
          return false;
        unordered_map<int,int>freq;
        for(auto x: hand){
            freq[x]++;
        }
        sort(hand.begin(),hand.end());
        for(auto x: hand){
            if(freq[x] == 0 ) continue;
            for(int j = 0; j<groupSize; j++){
                if(freq[x+j] == 0)
                  return false;
                freq[x+j]--; 
            }

        }

        return true;
    }
};
