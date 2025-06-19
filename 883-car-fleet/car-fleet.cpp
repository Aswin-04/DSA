class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        // TC --> O(N)
        // SC --> O(N)

        int n = position.size();
        map<int, int> mpp;

        for(int i=0; i < n; i++) {
            mpp[position[i]] = speed[i];
        }

        int fleets=1;
        auto it = mpp.rbegin();
        double prevTime = (target - it->first)/(double)it->second;
        it++;
        for(; it != mpp.rend(); it++) {
            double crntTime = (target - it->first)/(double)it->second;
            if(crntTime > prevTime) {
                fleets++;
                prevTime = crntTime;
            }
        }

        return fleets;
    }
};