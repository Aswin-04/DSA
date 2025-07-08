class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>> max_heap;

        for(int i=0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1]; 
            long long sqr = 1LL * (x*x) + (y*y);
            if(max_heap.size() < k) {
                max_heap.push({sqr, i});
            }
            else if(max_heap.top().first > sqr) {
                max_heap.pop();
                max_heap.push({sqr, i});
            }
        }

        vector<vector<int>> res;
        while(!max_heap.empty()) {
            int idx = max_heap.top().second; max_heap.pop();
            int x = points[idx][0];
            int y = points[idx][1];
            res.push_back({x, y});
        }

        return res;
    }
};