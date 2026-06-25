class Solution {
private:
    double calPow(double a ,double x , int n){
        if(n == 0) return a;
        if(n == 1) return a * x;
        if(n % 2 == 0) return calPow(a ,  x * x , n / 2);
        return calPow(a * x , x * x, n /2);
        
    }
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(x == 1 || n == 0) return 1;
        if(n < 0) x = 1 / x;
        double ans = calPow(1 , x , n);
        return ans;
    }
};