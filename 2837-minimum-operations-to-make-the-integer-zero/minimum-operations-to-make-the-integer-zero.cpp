class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
    //     int t =1;
    //     while(true){
    //         long long num = (long long )num1-(long long )(t*num2);
    //         if(num<0)return -1;
    //         else if(
    //             __builtin_popcount(num)<=t && t <=num
    //         )
    //         return t;
    //         t++;
    //     }
    //     return -1;

    for(int t =1; t<=36; t++){
        long long num = (long long )num1-(t*(long long )num2);
            if(num<0)return -1;
            else if(
                __builtin_popcountll(num)<=t && t <=num
            )
            return t;
    }
    return -1;
    }
};