import java.lang.*;
class Solution {
    public int maxProfit(int[] prices) {
        int prof=0;
        int buy=prices[0];

        for(int i=1 ; i<prices.length ; i++){
            buy = Math.min(buy, prices[i]);
            prof = Math.max(prof, prices[i]-buy);
        }
        return prof;
    }
}