class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int lo=0;
        int hi=arr.size()-1;
        int mid,idx;
        bool flag=false;
        while(lo<=hi){
            mid=lo+((hi-lo)/2);
            if(arr[mid]== target){
            flag=true;
            idx=mid;
            break;
            }
            else if(arr[mid]>target) hi=mid-1;
            else lo=mid+1;
        }
        if(flag==true) return idx;
        else return hi+1;
    }
};