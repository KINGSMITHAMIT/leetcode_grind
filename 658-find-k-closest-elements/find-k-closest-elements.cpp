// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         int n = arr.size();
//         vector<int> v(k);
//     int lo = 0;
//     int hi = n-1;

//     if(x < arr[0]){
//         // int i   = 0;
//     // while( i< k){
//     //     v[i] = arr[lo];
//     //     lo++;
//     //     i++;
//     // }
//         for(int  i =0; i< k; i++){
//             v[i] = arr[i];
//         }
//         return v;
        
//         }

//     if(x > arr[hi]){
//         int i   = n-1;
//     while( i< k){
//         v[i] = arr[hi];
//         hi--;
//         i--;
//     }
//         return v;
        
//     }

//         int i =0;
//     bool flag = false; // To chk whether the element is +nt or -nt
//     int lb,hb, nidx;
//     while(lo <= hi){
//         int mid = lo + (hi - lo)/2;
//         if(arr[mid] == x){
            
//             nidx = mid;
//             v[i] = arr[mid];
//             i++;
//             flag = true;
//             break;
//         }
//         else if(arr[mid] > x) hi = mid - 1;
//         else lo = mid + 1;
//     }
//         lb = hi;
//         hb = lo;
//     if(flag == true){
        
//         lb = nidx-1;
//         hb = nidx+1;
//     }
//         while(i<k && lb >= 0 && hb < n){
//             if(abs(arr[lb]- x) <= abs(arr[hb]-x)){
//                 v[i] = arr[lb];
//                 lb--;
//             }
            
//             else{
//                 v[i] = arr[hb];
//                 hb++;
//             }
//             i++;
//         }
    
//     if(hb > n){
//         while(i<k){
//             v[i] = arr[lb];
//             lb--;
//             i++;
//         }
//     }
//     if(lb <0){
//         while(i<k){
//             v[i]= arr[hb];
//             hb++;
//             i++;
//     }
//     }

    
//     sort(v.begin(), v.end());
//     return v;
//     }
// };
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    /* x is the target element and k is the number of element that we 
        we have to return in the vector */
        int n = arr.size();
        vector<int> ans(k);
        int target = x;
        // step 1: finding target in the array
        int i = 0; // pointer for filling the element in vector "ans"
        bool flag = 0;
        int lo = 0, hi = n-1;
        int mid; // we defined mid here so that we can use it later
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(arr[mid]==target){
                ans[i]=arr[mid];
                i++;
                flag = 1;
                break;
            }
            else if (arr[mid]>target) hi = mid - 1;
            else lo = mid + 1;
        }
        int ub = lo; // upper bount if target not found
        int lb = hi; // lower bound if target not found
        if(flag==1){
            // if target is available
            ub = mid + 1; 
            lb = mid - 1;
        }
        // filling the ans vector
        while(i<k && lb>=0 && ub<=n-1){
            /* abs is an inbuilt function for finding absolute value */
            int a = abs(target-arr[lb]);
            int b = abs(target-arr[ub]);
            if(a<=b){
                ans[i]=arr[lb];
                i++;
                lb--;
            }
            else{
                ans[i]=arr[ub];
                i++;
                ub++;
            }
        }
    // this loop will run if lb crossed 0 index and vector is still unfilled
        while(i<k && ub <= n-1){
            ans[i]=arr[ub];
            i++;
            ub++;
        }
    // this loop will run if ub crossed n-1 idx and vector is still unfilled
        while(i<k && lb>=0){
            ans[i]=arr[lb];
            i++;
            lb--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};