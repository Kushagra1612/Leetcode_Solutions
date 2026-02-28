class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0;
        int minProfit=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minProfit=min(minProfit,prices[i]);
            maxPro=max(maxPro,prices[i]-minProfit);

        }
        return maxPro;
    }
};