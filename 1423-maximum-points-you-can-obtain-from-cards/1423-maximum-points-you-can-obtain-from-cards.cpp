class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // Sum of first k cards (all taken from left)
        int total = 0;
        for (int i = 0; i < k; ++i) {
            total += cardPoints[i];
        }

        int maxPoints = total;

        
        int leftIndex = k - 1;
        int rightIndex = n - 1;

        for (int i = 0; i < k; ++i) {
            total -= cardPoints[leftIndex--];   
            total += cardPoints[rightIndex--];  
            maxPoints = max(maxPoints, total);
        }

        return maxPoints;
    }
};
