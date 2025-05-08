class Solution {
    public boolean isPalindrome(int x) {
        int temp=x;
        int lastDig;
        int ans=0;

        while(temp>0){
            lastDig=temp%10;
            ans=(ans*10)+lastDig;
            temp/=10;
        }
        return (ans==x) ? true : false;
    }
}