class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysBeforeMonth={0,31,59,90,120,151,181,212,243,273,304,334};

        auto getDayOfYear=[&](string date){
            int month=stoi(date.substr(0,2));
            int day=stoi(date.substr(3,2));
            return daysBeforeMonth[month-1]+day;
        };

        int a1=getDayOfYear(arriveAlice);
        int l1=getDayOfYear(leaveAlice);
        int a2=getDayOfYear(arriveBob);
        int l2=getDayOfYear(leaveBob);

        int startOverlap=max(a1,a2);
        int endOverlap=min(l1,l2);

        return max(0,endOverlap-startOverlap+1);
    }
};