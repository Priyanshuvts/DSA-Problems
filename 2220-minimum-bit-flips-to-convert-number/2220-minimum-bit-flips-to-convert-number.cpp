class Solution {
public:
    int minBitFlips(int s, int t) {
        int ct = 0;
        int x = s ^ t;
        while(x){
            ct += (x & 1);
            x = x >> 1;
        }
        return ct;
    }
};