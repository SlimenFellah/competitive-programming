#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); // Sort meetings by start time
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // Min-heap of ongoing meetings by end time
        priority_queue<int, vector<int>, greater<int>> freeRooms; // Min-heap of available room indices
        vector<int> roomUsage(n, 0); // Track number of meetings held in each room
        
        // Initialize free rooms heap with all room indices
        for (int i = 0; i < n; ++i) {
            freeRooms.push(i);
        }
        
        // Process each meeting
        for (auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            
            // Ensure no overlapping in meetings
            while (!minHeap.empty() && minHeap.top().first <= start) {
                int room = minHeap.top().second;
                minHeap.pop();
                freeRooms.push(room);
            }
            
            // Check for free rooms
            if (!freeRooms.empty() && freeRooms.top() <= start) {
                int room = freeRooms.top();
                freeRooms.pop();
                minHeap.push({end, room});
                roomUsage[room]++;
            } else {
                // No free rooms, need to wait for the next available room
                int room = minHeap.top().second;
                minHeap.pop();
                minHeap.push({end, room});
                roomUsage[room]++;
            }
        }
        
        // Find the room with the maximum number of meetings
        int maxMeetings = 0;
        int bestRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (roomUsage[i] > maxMeetings) {
                maxMeetings = roomUsage[i];
                bestRoom = i;
            }
        }
        if (bestRoom > 0) {
            return bestRoom - 1;
        } else {
            return bestRoom;
        }
    }
};