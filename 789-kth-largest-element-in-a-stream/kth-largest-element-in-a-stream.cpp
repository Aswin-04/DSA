class KthLargest {
public:
    int target;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    KthLargest(int k, vector<int>& nums) {
        target = k;
        for(int val: nums) {
            add(val);
        }
    }
    
    int add(int val) {
        if(min_heap.size() < target) {
            min_heap.push(val);
        } 

        else if(val > min_heap.top()) {
            min_heap.pop();
            min_heap.push(val);
        }

        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */