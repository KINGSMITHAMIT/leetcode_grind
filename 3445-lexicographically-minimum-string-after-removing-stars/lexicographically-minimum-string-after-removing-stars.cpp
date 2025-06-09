// class Solution {
// public:
//     string clearStars(string st) {
//         int idx=0;
//         stack<char>l, s;
//         for(const auto &it : st){
//             if(it=='*') {
//                 if(!l.empty())l.pop();
//             }
//             else l.push(it);
//         } 
//         // while(!s.empty()){
//         //     s.pop();
//         //     l.pop();
//         // }
//         string str="";
//         while(!l.empty()){
//             str+=l.top();
//             l.pop();
//         }
//         reverse(str.begin(),str.end());
//         return str;
//     }
// };

class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>>v(26);
        for(int i =0; i< s.size(); i++){
            if(s[i]!='*')   v[s[i]-'a'].push_back(i);
            else {
                int i=0;
                while(v[i].empty())i++;
                
                    s[v[i][v[i].size()-1]]='*';
                    v[i].pop_back();
                
            }
        }

            string str;
        for(int i =0; i<s.size(); i++){
            if(s[i]!='*') str+=s[i];
        }
        return str;
    }
};