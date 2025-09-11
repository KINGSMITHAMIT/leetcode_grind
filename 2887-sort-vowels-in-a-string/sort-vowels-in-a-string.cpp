class Solution {
public:
    string sortVowels(string s) {
     vector<char>sorted;
     for(auto &it: s) 
     if(it == 'A'|| it == 'E'|| it == 'I' || it== 'O'|| it == 'U'|| it == 'a'|| it == 'e'|| it == 'i'|| it == 'o'|| it == 'u')
     sorted.push_back(it);
     sort(sorted.begin(), sorted.end());
    //  for(auto &it :sorted) cout<<it<<" ";
    //  cout<<"\n";
     string st; int p=0; 
     for(auto &it :s) {
        if(it == 'A'|| it == 'E'|| it == 'I' || it== 'O'|| it == 'U'|| it == 'a'|| it == 'e'|| it == 'i'|| it == 'o'|| it == 'u'){
            st+=sorted[p];
            p++;
        }

        else st+=it;
     }  
     return st;
    }
};