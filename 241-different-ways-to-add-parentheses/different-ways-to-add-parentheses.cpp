class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>result;
        if(expression.size()<=2){
            result.push_back(stoi(expression));
            return result;
        }
        int n = expression.size();
        for(int i =0; i<n; i++){
            if(isdigit(expression[i]))continue;
            vector<int>left= diffWaysToCompute(expression.substr(0,i));
            vector<int>right= diffWaysToCompute(expression.substr(i+1));
                int val=0;
                for(auto &lv: left){
                    for(auto &rv:right){
                        if(expression[i]=='+') val = lv+rv;
                        else if(expression[i]=='-') val = lv-rv;
                        else val = lv*rv;
                        result.push_back(val);
                    }
                }
        }
        return result;
    }
};