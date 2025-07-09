class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() && minHeap.empty()) {
            maxHeap.push(num);
        } 
        else if(maxHeap.size() == minHeap.size()) {
            if(num <= minHeap.top()) {
                maxHeap.push(num);
            }
            else minHeap.push(num);
        }

        else if(maxHeap.size() > minHeap.size()) {
            int top = maxHeap.top();
            if(num >= top) {
                minHeap.push(num);
            }
            else {
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(top);
            }
        }

        else {
            int top = minHeap.top();
            if(num <= top) {
                maxHeap.push(num);
            }
            else {
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(top);
            }
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            return (double)(maxHeap.top()+minHeap.top())/(double)2;
        }

        if(maxHeap.size() > minHeap.size()) {
            return (double)maxHeap.top();
        }

        return (double)minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */