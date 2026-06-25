class Solution {
public:
    double myPow(double x, int n) {
        long long a = n;
        if(a < 0) {
            a = -a;
            x = 1/x;
        }
        double ans = 1.0;
        while(a > 0){
            if(a %2 == 1){
                ans *= x;
            }
            x *= x;
            a /= 2;
        }
        return ans;
    }
};