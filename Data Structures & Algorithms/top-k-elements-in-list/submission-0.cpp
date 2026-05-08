class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
         //find frequency of each element in array
             for (int x : nums) {
                 freq[x]++;
                }
        //sorting
        vector<pair<int,int>> v;
for (auto p : freq) {
    v.push_back(p);
}
sort(v.begin(), v.end(), [](auto &a, auto &b) {
    return a.second > b.second;  // descending frequency
});

      vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(v[i].first);
        }

        return result;
    }    

        
    
};
