class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minPos=minutes/5.0;
        double hourPos=(double)hour+minPos/12.0;
        double degree=abs(minPos-hourPos)*30.0;
        degree=min(degree,360.0-degree);
        return degree;
        
    }
};