import java.lang.*;
class Solution {
    public int maxProfit(int[] prices) {
        int prof=0;
        int buy=prices[0];

        for(int i=1 ; i<prices.length ; i++){
            if( prices[i] < buy ) buy = prices[i];
            else if(prices[i]-buy > prof) prof = prices[i]-buy;
        }
        return prof;
    }
}