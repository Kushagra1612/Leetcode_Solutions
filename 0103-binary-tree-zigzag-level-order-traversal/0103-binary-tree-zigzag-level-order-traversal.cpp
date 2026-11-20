class Solution {
public:
   vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<deque<int>> result;
    dfs(root, 0, result);
    vector<vector<int>> ans;
    for (auto& d : result) ans.push_back(vector<int>(d.begin(), d.end()));
    return ans;
}

void dfs(TreeNode* node, int depth, vector<deque<int>>& result) {
    if (!node) return;
    if (depth == (int)result.size()) {
        result.push_back({});
    }
    if (depth % 2 == 0) {
        result[depth].push_back(node->val);
    } else {
        result[depth].push_front(node->val);
    }
    dfs(node->left, depth + 1, result);
    dfs(node->right, depth + 1, result);
}
};