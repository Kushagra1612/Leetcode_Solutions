class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> heap;
        for (auto& entry : freq) {
            heap.push({entry.second, entry.first});
        }

        string result;
        while (!heap.empty()) {
            auto [count, ch] = heap.top();
            heap.pop();
            result.append(count, ch);
        }
        return result;
    }
};