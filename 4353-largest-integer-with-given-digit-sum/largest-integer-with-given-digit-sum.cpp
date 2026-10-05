class Solution {
public:
    int largestInteger(int n, int s) {
        if(s == 0)
        return 0;
        if(s > 9 * n)
        return -1;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(s > 9) {
                ans = ans * 10 + 9;
                s -= 9;
            } else {
                ans = ans * 10 + s;
                s = 0;
            }
        }
        return ans;
    }
};