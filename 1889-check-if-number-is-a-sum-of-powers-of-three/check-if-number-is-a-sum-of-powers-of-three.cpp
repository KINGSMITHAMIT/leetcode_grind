class Solution {
public:
    bool checkPowersOfThree(int n) {
        bool chk =true;
        while(n>0){
            int r=n%3;
            if(r==2){
                chk=false;
                break;
            }
            n/=3;
        }if(chk==true) return true;
        else return false;
    }
};