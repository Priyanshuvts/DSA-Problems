class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag = false;
        if((dividend < 0 && divisor < 0) ||(dividend > 0 && divisor > 0)) flag = true;
        long dnd = dividend == INT_MIN ? long(INT_MAX) + 1:abs(dividend);
        long dsr = divisor == INT_MIN ? long(INT_MAX) + 1:abs(divisor);
        long ans = 0;
        while(dnd >= dsr){
            long pwr = 1;
            while(dnd >= dsr*pwr*2 ){
                pwr = pwr << 1;
            }
            dnd -= dsr * pwr;
            ans += pwr;
        }
        if(flag == true && ans > INT_MAX) return INT_MAX;
        if(flag == false && -ans < INT_MIN) return INT_MIN;
        if(flag) return ans;
        return -ans;
    }
};