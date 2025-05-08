class Solution {
    public int reverse(int x) {
        int temp=x;
        if (x<0) temp=Math.abs(x);

        int ans=0;
        int lastDig;

        while(temp>0){
            lastDig= temp%10;
            if (ans > Integer.MAX_VALUE / 10 || (ans == Integer.MAX_VALUE / 10 && lastDig > 7)) return 0;
            if (ans < Integer.MIN_VALUE / 10 || (ans == Integer.MIN_VALUE / 10 && lastDig < -8)) return 0;
     
            ans=(ans*10)+lastDig;
            temp/=10;
            }
        return (x<0) ? -ans : ans;
    }
}