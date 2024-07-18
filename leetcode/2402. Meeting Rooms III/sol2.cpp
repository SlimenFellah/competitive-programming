#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by start time; if start time is the same, sort by end time
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap of end times of ongoing meetings
        
        // Process each meeting
        for (auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            
            // Check for meetings that have ended by the start time of current meeting
            while (!minHeap.empty() && minHeap.top() <= start) {
                minHeap.pop();
            }
            
            // Add the current meeting's end time to the heap
            minHeap.push(end);
        }
        
        // The size of minHeap is the maximum number of overlapping meetings
        return minHeap.size();
    }
};
