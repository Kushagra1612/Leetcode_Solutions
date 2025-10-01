class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(n, 0, 0, "", result);
        return result;
    }

private:
    void backtrack(int n, int openCount, int closeCount, std::string currentString, std::vector<std::string>& result) {
        if (openCount == n && closeCount == n) {
            result.push_back(currentString);
            return;
        }

        if (openCount < n) {
            backtrack(n, openCount + 1, closeCount, currentString + '(', result);
        }

        if (closeCount < openCount) {
            backtrack(n, openCount, closeCount + 1, currentString + ')', result);
        }
    }
};