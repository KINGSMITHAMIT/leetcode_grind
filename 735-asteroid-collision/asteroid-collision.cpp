class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;

        for (int i = 0; i < arr.size(); ++i) {
            bool exploded = false;

            while (!st.empty() && arr[i] < 0 && st.top() > 0) {
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

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
