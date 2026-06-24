class Solution {
public:
    int myAtoi(string s) {
        long x = 0;
        int i = 0;
        bool pve = true;
        while(!(s[i] >= '0' && s[i] <= '9') && i < s.size()){
            if(s[i] == ' ') i++;
            else if(s[i] == '-'){
                pve = false;
                i ++;
                break;
            }
            else if(s[i] == '+'){
                i ++;
                break;
            }
            else return 0;
        }
        while(i < s.size()){
            if(s[i] >= '0' && s[i] <= '9')
            {
                if(pve){
                    x = x * 10 + (s[i] - '0');
                    if(x / 10 > INT_MAX / 10) return INT_MAX;
                    else if(x / 10 == INT_MAX / 10){
                        if(x % 10 > INT_MAX % 10) return INT_MAX;
                    }
                }
                else{
                    if(x == 0) x = -(s[i] - '0');
                    else x = x * 10 - (s[i] - '0');
                    if(x / 10 < INT_MIN / 10) return INT_MIN;
                    else if(x / 10 == INT_MIN / 10){
                        if(x % 10 < INT_MIN % 10) return INT_MIN;
                    }
                }
                i ++;
            }
            else return x;
        }
        return x;
    }
};