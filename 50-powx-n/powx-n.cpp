class Solution {
public:
    double myPow(double x, long n) {
    
    if(n<0){
        x = 1/x;
        n = -n;
    }

    if(n == 0)
    return 1;
    double temp = myPow(x, n / 2);
    if(n & 1)
    return temp * temp * x;
    else
    return temp * temp;

    }

};