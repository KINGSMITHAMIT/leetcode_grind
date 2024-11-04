class Solution {
public:
    string compressedString(string word) {
        string ans="";
        for(int i=0;i<word.size();i++){
            int cnt=1;
            while(word[i]==word[i+1] && cnt<9){
                i++;
                cnt++;
            }
            ans+=to_string(cnt)+word[i];
        }
        return ans;
    }
};