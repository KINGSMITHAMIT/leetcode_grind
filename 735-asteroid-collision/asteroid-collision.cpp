class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        
        for (int i = 0; i < arr.size(); i++) {
            bool exploded = false;

            while (!st.empty() && st.top() > 0 && arr[i] < 0) {
                if (abs(st.top()) < abs(arr[i])) {
                    st.pop();
                } else if (abs(st.top()) == abs(arr[i])) {
                    st.pop();
                    exploded = true;
                    break;
                } else {
                    exploded = true;
                    break;
                }
            }

            if (!exploded) {
                st.push(arr[i]);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
