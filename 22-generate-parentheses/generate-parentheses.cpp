class Solution {
public:
    vector<string>ans;
    void help(int i ,int n, int openBrac, string st){
        if(i>=(n*2)) {
           if(openBrac == 0) ans.push_back(st);
            return;
        }
        // i can go with an '(' at the start
        // st+='(';
        help(i+1, n, openBrac+1, st+'(');
        // st.pop_back(); // for backtrack
        // i can push an ')' only if there is a open brac 
        if(openBrac >0 ) {
            // st+=')';
            help(i+1,n, openBrac-1, st+')');
            // st.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string st="";
        help(0,n,0,st);
        return ans;   
    }
};