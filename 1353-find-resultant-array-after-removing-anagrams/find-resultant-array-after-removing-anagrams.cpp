class Solution {
public:
    bool checkAna(string a, string b){
        int n = a.length();
        int m = b.length();
        if(n!=m) return 0;
        else{
            vector<int>v(26,0);
            for(auto &it: a){
                int pos = it-'a';// we are trying to increase the freq right how should we do it like should we i get the chare a-
                v[pos]++;
            }
            for(auto &it: b){
                int pos = it-'a';// we are trying to increase the freq right how should we do it like should we i get the chare a-
                v[pos]--;
            }
            for(auto &it :v){
                if(it!=0)return 0;
            }
        return 1;
        }
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        ans.push_back(words[0]);
        for(int i =1 ; i< words.size(); i++){
            if(!checkAna(words[i], ans.back()))ans.push_back(words[i]);
        }
        return ans;
    }
};