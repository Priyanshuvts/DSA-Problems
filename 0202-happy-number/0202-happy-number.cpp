class Solution {
private:
    int sq_sum(int n){
        int sm = 0;
        while(n){
            int digit = n % 10;
            sm += digit * digit;
            n /= 10;
        }
        return sm;
    }
public:
    bool isHappy(int n) {
        while(true){
            if(n == 1) return true;
            if(n == 4) return false;
            n = sq_sum(n);
        }
        return false;
    }
};