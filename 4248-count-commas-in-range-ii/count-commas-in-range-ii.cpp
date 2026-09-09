class Solution {
public:
    long long countCommas(long long n) {
        long long i = n;
        long long dig = 0;
        long long ans = 0;
        while(i) {
            dig++;
            i = i / 10;
        }
        if(dig <= 3)
        return 0;
        for(int i = 4; i < dig; i++) {
            int com = i / 3;
            if(i % 3 == 0)
            com--;
            ans += com * 9 * pow(10, i - 1);
        }
        int com = dig / 3;
        if(dig % 3 == 0)
        com--;
        ans += com * (n - pow((long long)10, dig - 1) + 1);
        return ans;
    }
};