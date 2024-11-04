/*
class Solution {
public:
    int calPoints(vector<string>& st) {
        stack<int> val;
        for(int i = 0; i<st.size(); i++){
            if(empty(val)) val.push(stoi(st[i]));
            else if(isdigit(st[i][0])||st[i][0] == '-' && isdigit(st[i][1])) val.push(val.top()+stoi(st[i]));
            else if(st[i]=="+") {
                stack<int> dummy;
                int v1 = val.top();
                dummy.push(v1);
                val.pop();
                int v2 = val.top();
                dummy.push(v2);
                val.pop();
                val.push(dummy.top());
                dummy.pop();
                val.push(dummy.top());
                dummy.pop();
                val.push(v1+v2);
            } 
            else if(st[i] == "D") val.push(2*val.top());
            
            else if(st[i] ==  "C") val.pop();
        }
        int sum = 0;
        while(!val.empty()){
            sum+= val.top();
            val.pop();
        }
        return sum;
    }
};
*/
class Solution {
public:
    int calPoints(vector<string>& st) {
        stack<int> val;
        for (int i = 0; i < st.size(); i++) {
            if (val.empty()) {
                val.push(stoi(st[i]));
            } else if (isdigit(st[i][0]) || (st[i][0] == '-' && isdigit(st[i][1]))) {
                val.push(stoi(st[i]));
            } else if (st[i] == "+") {
                int top1 = val.top();
                val.pop();
                int top2 = val.top();
                val.push(top1);
                val.push(top1 + top2);
            } else if (st[i] == "D") {
                val.push(2 * val.top());
            } else if (st[i] == "C") {
                val.pop();
            }
        }
        int sum = 0;
        while (!val.empty()) {
            sum += val.top();
            val.pop();
        }
        return sum;

    }
};