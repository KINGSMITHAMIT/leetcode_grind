class Solution {
public:
    int possibleStringCount(string word) {
        int extra = 0;
        for(int i =1; i<word.size(); i++) {
            int freq=1;
            if(word[i]==word[i-1]) freq++;
            if(freq>1) extra++;
        }
        return extra+1;
    }

};