class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        
        int max=prices[0];
        int buy=prices[0];
        
        for(int i=1; i<prices.size(); i++){
            
            if(buy > prices[i] && prices[i]>0 && i+1 <= prices.size()-1){
                buy=prices[i];
                max=prices[i+1];
            }
            if(max < prices[i]){
                max=prices[i];
            }
        }
        cout << max <<endl;
        cout << buy;

        if((max-buy)<0) return 0;
        return max-buy;
    }
};