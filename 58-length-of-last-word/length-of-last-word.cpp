class Solution {
public:
    int lengthOfLastWord(string s) {
        long long int count = 0;
        long long int j =0;
       while(j<s.length()-1){
            if(s[j] == ' ' && s[j+1] != ' ' )   count =0;
            if(s[j] != ' ') count++;
            j++;
        }
            if(s[s.length()-1] != ' ') count++;
        return count;
    }
};