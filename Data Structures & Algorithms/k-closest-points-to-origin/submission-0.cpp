class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    
      int dist;
      priority_queue<pair<int,int>>pq;
      vector<vector<int>>output;
      
      for(int i = 0; i<points.size(); i++){
        int x = points[i][0];
        int y = points[i][1];
        dist = x*x + y*y;
        pq.push({dist,i});
        if(pq.size()>k)
          pq.pop();
        
      }  
      while(!pq.empty()){
        output.push_back(points[pq.top().second]);
        pq.pop();
      }
     
      return output; 

      
    }
};
