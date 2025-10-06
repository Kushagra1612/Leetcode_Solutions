class Solution {
private:
    bool isPalindrome(const std::string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void func(int index, const std::string& s, std::vector<std::string>& path,
              std::vector<std::vector<std::string>>& res) {
        
        if (index == s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); ++i) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                func(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> path;
        func(0, s, path, res);
        return res;
    }
};