#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility> // For std::pair

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if(rectangles.empty()) return false;

        // Use long long for area to prevent overflow
        long long totalArea = 0;

        // Initialize boundaries with the first rectangle
        int minX = rectangles[0][0];
        int minY = rectangles[0][1];
        int maxX = rectangles[0][2];
        int maxY = rectangles[0][3];

        // Set to store corners "x,y"
        // We use a set to "toggle" corners. 
        // If a corner appears an odd number of times (1, 3), it stays.
        // If a corner appears an even number of times (2, 4), it is removed.
        set<pair<int, int>> corners;

        for(const auto& rect : rectangles){
            int x = rect[0];
            int y = rect[1];
            int a = rect[2];
            int b = rect[3];

            // 1. Update the Bounding Box
            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, a);
            maxY = max(maxY, b);

            // 2. Accumulate Area
            totalArea += (long long)(a - x) * (b - y);

            // 3. Toggle Corners in the set
            // Helper lambda to toggle a point
            auto toggle = [&](pair<int, int> p) {
                if(corners.count(p)) corners.erase(p);
                else corners.insert(p);
            };

            toggle({x, y}); // Bottom-left
            toggle({x, b}); // Top-left
            toggle({a, y}); // Bottom-right
            toggle({a, b}); // Top-right
        }

        // CHECK 1: Area Match
        // The sum of all small rectangle areas must equal the area of the large bounding box
        long long expectedArea = (long long)(maxX - minX) * (maxY - minY);
        if (totalArea != expectedArea) return false;

        // CHECK 2: Corner Count
        // After cancelling out internal corners (which meet in groups of 2 or 4),
        // we should strictly have 4 corners left.
        if(corners.size() != 4) return false;

        // CHECK 3: Correct Corners
        // The 4 remaining corners MUST be the exact corners of the bounding box.
        if(!corners.count({minX, minY}) || 
           !corners.count({minX, maxY}) || 
           !corners.count({maxX, minY}) || 
           !corners.count({maxX, maxY})){
            return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha; // Print "true"/"false"

    // Test Case 1: Valid Perfect Rectangle
    // [1,1,3,3], [3,1,4,2], [3,2,4,4], [1,3,2,4], [2,3,3,4]
    // These form a large rectangle from (1,1) to (4,4) with no gaps/overlaps.
    vector<vector<int>> rects1 = {
        {1,1,3,3}, {3,1,4,2}, {3,2,4,4}, {1,3,2,4}, {2,3,3,4}
    };
    cout << "Test Case 1 (Valid): " << sol.isRectangleCover(rects1) << endl; // Expected: true

    // Test Case 2: Gap
    // [1,1,2,3], [1,3,2,4], [3,1,4,2], [3,2,4,4]
    // Missing the middle part between x=2 and x=3.
    vector<vector<int>> rects2 = {
        {1,1,2,3}, {1,3,2,4}, {3,1,4,2}, {3,2,4,4}
    };
    cout << "Test Case 2 (Gap): " << sol.isRectangleCover(rects2) << endl; // Expected: false

    // Test Case 3: Overlap
    // [1,1,3,3], [3,1,4,2], [1,3,2,4], [2,2,4,4]
    // Rect [2,2,4,4] overlaps with [1,1,3,3] and others.
    vector<vector<int>> rects3 = {
        {1,1,3,3}, {3,1,4,2}, {1,3,2,4}, {2,2,4,4}
    };
    cout << "Test Case 3 (Overlap): " << sol.isRectangleCover(rects3) << endl; // Expected: false

    return 0;
}