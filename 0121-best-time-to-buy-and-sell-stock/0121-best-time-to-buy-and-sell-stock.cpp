class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minProfit=prices[0];
        int maxProfit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minProfit){
                minProfit=prices[i];
            }
            else{
                int profit=prices[i]-minProfit;
                if(profit> maxProfit){
                    maxProfit=profit;
                }
            }
        }
        return maxProfit;
    }
};