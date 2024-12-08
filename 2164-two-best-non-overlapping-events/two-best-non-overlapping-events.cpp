class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort on end time
        auto cmpEnd = [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmpEnd)> pq(cmpEnd);

        // Sort on start time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int prevMax = 0;
        int res = 0;
        for (const auto& event : events) {
            // Find prevMax
            while (!pq.empty() && pq.top()[1] < event[0]) {
                prevMax = max(prevMax, pq.top()[2]);
                pq.pop();
            }
            res = max(res, prevMax + event[2]);
            pq.push(event);
        }
        return res;
    }
};

