class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , [](vector<int>& a , vector<int> & b){
            return a[1] < b[1];
        });
        int min_free = intervals[0][1] , ct = 0 , n = intervals.size();
        for(int i= 1; i < n; i ++){
            if(intervals[i][0] >= min_free){
                min_free = intervals[i][1];
            }
            else{
                ct ++;
            }
        }
        return ct;
    }
};