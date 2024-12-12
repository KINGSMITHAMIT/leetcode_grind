class Solution {
public:
    int countStudents(vector<int>& qu, vector<int>& s) {
        queue<int> q;
        for (int student : qu) {
            q.push(student);
        }

        int sandwichIndex = 0;
        int attempts = 0;

        while (!q.empty() && attempts < q.size()) {
            if (q.front() == s[sandwichIndex]) {
                q.pop();
                sandwichIndex++;
                attempts = 0; // Reset attempts after a successful match
            } else {
                q.push(q.front());
                q.pop();
                attempts++;
            }
        }

        return q.size();
    }
};
