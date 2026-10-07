class Solution {
public:
    long long power(int x, long long n) {
        if(n == 0 || x == 1)
        return 1;
        long long NUM = pow(10, 9) + 7;
        long long temp = power(x, n / 2);
        if(n & 1)
        return (x * temp * temp) % NUM;
        return (temp * temp) % NUM;
    }

    int countGoodNumbers(long long n) {
        long long even, odd;
        even = odd = n / 2;
        if(n & 1)
        even++;
        long long NUM = pow(10, 9) + 7;
        return (power(5, even) * power(4, odd)) % NUM;
    }
};