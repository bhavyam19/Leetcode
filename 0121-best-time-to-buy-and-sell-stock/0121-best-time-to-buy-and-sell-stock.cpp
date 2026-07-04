class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mprofit = 0;
        int i = 0;
        int j = 1;
        while(j<prices.size()){
            if(prices[j]>prices[i]){
                profit = prices[j]-prices[i];
                mprofit = max(profit,mprofit);
            }else{
                i = j;
            }
            j++;
        }
        return mprofit;
    }   
};