class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        if(n == 0 || k==0 ) return {};
        if(k ==1)  return arr;
        stack<int> st;
        st.push(n-1);
        vector<int> ans;
        ans.push_back(n);    
        for(int i = n-2; i>=0; i--){
            while(st.size() != 0 && arr[st.top()]< arr[i]) st.pop();
            if(st.size()== 0) ans.push_back(n);
            else ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        
    
    vector<int> result;
    for(int i = 0; i< n-k+1; i++){
    //For getting all the windows
    int j = i;
    while(ans[j] < i+k) j = ans[j];
    result.push_back(arr[j]);
    }
        return result;
    }
};
/*
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0 || k == 0) return {}; // edge case: empty array or k = 0
        if (k == 1) return arr; // edge case: k = 1

        stack<int> st;
        st.push(n-1);
        vector<int> ans(n);
        ans[n-1] = n; 
        
        for (int i = n-2; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if (st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }

        vector<int> result;
        for (int i = 0; i < n - k + 1; ++i) {
            int j = i;
            while (ans[j] < i + k) j = ans[j];
            result.push_back(arr[j]);
        }

        return result;
    }
};
*/