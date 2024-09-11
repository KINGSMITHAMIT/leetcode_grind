class Solution {
public:
    int minBitFlips(int start, int goal) {
        start=start^goal;
        int cnt=0;
        while(start>1){
            if(start%2==1) cnt++;
            start=start/2;
        }
        if(start==1) cnt++;
        return cnt;
    }
};