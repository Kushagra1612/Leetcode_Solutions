class Solution {
public:
   int numMatchingSubseq(string s, vector<string>& words) {
    // Record every index of each character in s
    vector<vector<int>> positions(26);
    for (int i = 0; i < s.size(); i++) {
        positions[s[i] - 'a'].push_back(i);
    }

    int count = 0;
    for (const string& word : words) {
        int prev = -1;
        bool matched = true;
        for (char c : word) {
            vector<int>& idxs = positions[c - 'a'];
            int j = upper_bound(idxs.begin(), idxs.end(), prev) - idxs.begin();
            if (j == idxs.size()) {
                matched = false;
                break;
            }
            prev = idxs[j];
        }
        if (matched) count++;
    }
    return count;
}
};