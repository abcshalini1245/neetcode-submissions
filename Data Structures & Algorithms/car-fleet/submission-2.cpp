class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>cars;  //distance,time
        //calculate time for each
        for(int i =0; i<position.size(); i++){
          double time = double(target - position[i])/speed[i];
          cars.push_back({position[i],time});
        }
        //sort in descending
        sort(cars.begin(), cars.end(), greater<>());

        //Use a stack / variable to track fleets
               // If a car takes more time than the fleet ahead → new fleet
               //Else → it joins the fleet ahead
        int fleet=0;
        double maxtime =0;

        // for(auto &car: cars){
        //     if(car.second > maxtime){
        //        fleet++;
        //        maxtime = car.second;
        //     }
                
        // }

        // return fleet;


        //using stack
        stack<double>st;
        for(auto &car: cars){
            if( st.empty() || car.second  > st.top()){
               st.push(car.second);
            }
        }
        return st.size();
    }
};
