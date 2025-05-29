class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int>ump;
        int count=0;
        
        for(int i=0; i<words.size(); i++){
            string str= words[i];
            reverse(str.begin(),str.end());
            if(ump[str]>0) {
                count+=4;
                ump[str]--;
                }
            else ump[words[i]]++;
            
        }
        
            for(const auto &[it,x]: ump){
                if(x>0){
                string st= it;
                reverse(st.begin(), st.end());
                if(it== st) {
                    count+=2;
                    break;
                    }
                }
            }
        
        return count;
    }
};