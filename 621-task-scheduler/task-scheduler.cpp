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
                time = queue.front().second;
            } else {
                int cnt = maxHeap.top() -1; maxHeap.pop();
                time++;
                if(cnt > 0) {
                    queue.push({cnt, n+time});
                }
            }

            if(!queue.empty() && queue.front().second == time) {
                maxHeap.push(queue.front().first);
                queue.pop();
            }
        }

        return time;
    }
};