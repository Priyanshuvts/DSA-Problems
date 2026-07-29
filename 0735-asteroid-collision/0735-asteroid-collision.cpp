class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        vector<int> ans ;
        for(int i = 0; i < n; i ++){
            if(ans.size() == 0 || a[i] >0) 
                ans.push_back(a[i]);
            else{
                if(ans.size() > 0 && ans.back() < 0)
                    ans.push_back(a[i]);
                else{
                    while (!ans.empty() && ans.back() > 0 &&
                           abs(ans.back()) < abs(a[i])) {
                        ans.pop_back();
                    }

                    if (ans.empty() || ans.back() < 0)
                        ans.push_back(a[i]);
                    else if (abs(ans.back()) == abs(a[i]))
                        ans.pop_back();                  
                }
            }
        }
        return ans;
    }
};