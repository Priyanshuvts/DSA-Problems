class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int sr = 0;
        for(int  i = 0; i < n ; ++ i){
            if(((details[i][11] - '0') * 10 + details[i][12] - '0') > 60) sr ++;
        }
        return sr;
    }
};