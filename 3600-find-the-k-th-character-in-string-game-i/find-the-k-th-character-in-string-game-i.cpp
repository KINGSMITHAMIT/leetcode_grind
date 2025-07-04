class Solution {
public:
    char kthCharacter(int k) {
        int c = 0;
        while(k>1){
        if((k & (k - 1)) == 0) k-= (int)(1<<((int)log2(k)-1));
        else k-= (int)(1<<(int)log2(k));
            c++;
        }
        return (char)97+c;
    }
};