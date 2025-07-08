class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26];
        priority_queue<int> maxHeap;
        int time = 0;
        queue<pair<int, int>> queue;
        for(char ch: tasks) {
            freq[ch-'A']++;
        }
        for(int i=0; i < 26; i++) {
            if(freq[i]) maxHeap.push(freq[i]);
        }

        while(!maxHeap.empty() || !queue.empty()) {

            if(maxHeap.empty()) {
                pair<int, int> pr = queue.front(); queue.pop();
                int taskCnt = pr.first;
                int closingTime = pr.second;
                time += closingTime - time;
                maxHeap.push(taskCnt);
                continue;
            }

            if(!queue.empty()) {
                pair<int, int> pr = queue.front();
                int taskCnt = pr.first;
                int closingTime = pr.second;
                if(time == closingTime) {
                    queue.pop();
                    maxHeap.push(taskCnt);
                    continue;
                }
            }

            int currentTaskCnt = maxHeap.top(); maxHeap.pop();
            time++;
            if(--currentTaskCnt > 0) queue.push({currentTaskCnt, n+time});
        }

        return time;
    }
};