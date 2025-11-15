class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char t : tasks) freq[t]++;

        priority_queue<int> maxHeap;
        for (auto &p : freq) maxHeap.push(p.second);

        queue<pair<int,int>> q;  
        int time = 0;

        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int cnt = maxHeap.top(); 
                maxHeap.pop();
                cnt--;

                if (cnt > 0)
                    q.push({cnt, time + n});
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
