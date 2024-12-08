class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort on start time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int prevMax = 0, res = 0;

        for (const auto& event : events) {
            // Maintain the max value of events that have ended before the current event starts
            while (!pq.empty() && pq.top().first < event[0]) {
                prevMax = max(prevMax, pq.top().second);
                pq.pop();
            }

            // Update the result with the maximum possible value of two non-overlapping events
            res = max(res, prevMax + event[2]);

            // Add the current event to the priority queue
            pq.emplace(event[1], event[2]);
        }

        return res;
    }
};

