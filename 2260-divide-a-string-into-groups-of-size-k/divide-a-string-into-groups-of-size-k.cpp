class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>v;
        int n = s.size();
        for(int i =0; i<(n-(n%k)); i+=k)   v.push_back(s.substr(i,k));
        if (n%k == 0 ) return v;
        else {
            string str = s.substr((s.size()-(n%k)),(n%k));
            while(str.length()<k) str+= fill;
            v.push_back(str);
            return v;
        }
    }
};