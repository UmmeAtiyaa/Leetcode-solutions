class Solution {
    public int reverse(int x) {
        int ans = 0;
        
        while (x != 0) {
            int lastDig = x % 10;

            // Check overflow BEFORE it happens
            if (ans > Integer.MAX_VALUE / 10 || (ans == Integer.MAX_VALUE / 10 && lastDig > 7)) return 0;
            if (ans < Integer.MIN_VALUE / 10 || (ans == Integer.MIN_VALUE / 10 && lastDig < -8)) return 0;

            ans = ans * 10 + lastDig;
            x /= 10;
        }
        
        return ans;
    }
}
