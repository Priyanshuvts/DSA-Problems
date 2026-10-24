class Solution {
int num (string date , int i , int j){
    return (date[i] - '0') * 10 + date[j] - '0';
}
int To_days(string date , vector<int> & days){
    int ans = 0;
    ans += days[num(date , 0 , 1) - 1];
    ans += num(date, 3 , 4);
    return ans;
}
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = 1;  i < days.size() ; i ++){
            days[i] = days[i - 1] + days[i];
        }
        int start = max(To_days(arriveAlice , days) , To_days(arriveBob , days));
        int end = min(To_days(leaveAlice,days) , To_days(leaveBob , days));
        return max(0, end - start + 1);
    }
};