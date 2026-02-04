#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int MOD = 1e9 + 7;

        // Step 1: Coordinate Compression
        // We need sorted unique coordinates to map the large 10^9 values
        // to small indices (0, 1, 2...).
        set<int> sx, sy;
        for (auto& r : rectangles) {
            sx.insert(r[0]);
            sx.insert(r[2]);
            sy.insert(r[1]);
            sy.insert(r[3]);
        }

        // Convert sets to vectors for easy indexing
        vector<int> X(sx.begin(), sx.end());
        vector<int> Y(sy.begin(), sy.end());

        // Map actual coordinates to their compressed index
        unordered_map<int, int> xmp, ymp;
        for(int i = 0 ; i < X.size() ; i++) xmp[X[i]] = i;
        for(int i = 0 ; i < Y.size() ; i++) ymp[Y[i]] = i;

        int w = X.size();
        int h = Y.size();
        
        // Create a 2D grid to track coverage counts.
        // col[i][j] will eventually store how many rectangles cover the 
        // region defined by X[i]..X[i+1] and Y[j]..Y[j+1].
        vector<vector<int>> col(w, vector<int>(h + 1, 0));

        // Step 2: Fill the grid using Difference Array technique
        for(auto& r : rectangles){
            int x1 = xmp[r[0]], x2 = xmp[r[2]];
            int y1 = ymp[r[1]], y2 = ymp[r[3]];

            // For every horizontal strip (x interval) covered by the rectangle,
            // mark the vertical range (y interval) it covers.
            for(int x = x1 ; x < x2 ; x++){
                col[x][y1] += 1;
                col[x][y2] -= 1;
            }
        }

        // Step 3: Compute Prefix Sums
        // This converts the difference markers (+1, -1) into actual coverage counts.
        for(int x = 0 ; x < w ; x++){
            for(int y = 1 ; y < h ; y++){
                col[x][y] += col[x][y-1];
            }
        }

        // Step 4: Calculate Total Area
        long long area = 0;
        // Iterate through valid intervals. X has w points, so it has w-1 intervals.
        for(int x = 0 ; x + 1 < w ; x++){
            for(int y = 0 ; y + 1 < h ; y++){
                // If col[x][y] > 0, this block is covered by at least one rectangle.
                if(col[x][y] > 0){
                    long long dx = (long long)X[x+1] - X[x];
                    long long dy = (long long)Y[y+1] - Y[y];
                    
                    // FIXED: Was dy*dy, changed to dx*dy
                    area = (area + dx * dy) % MOD;
                }
            }
        }
        return (int)area;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Simple Overlap
    // Rect 1: (0,0) to (2,2), Area = 4
    // Rect 2: (1,0) to (2,3), Area = 1*3 = 3
    // Intersection: (1,0) to (2,2), Area = 2
    // Union Area = 4 + 3 - 2 = 5
    vector<vector<int>> rects1 = {{0,0,2,2}, {1,0,2,3}, {1,0,3,1}};
    // Let's trace carefully: 
    // R1: 0,0,2,2 -> 4
    // R2: 1,0,2,3 -> 3 (overlaps R1 in x:1-2, y:0-2)
    // R3: 1,0,3,1 -> 2 (overlaps R1 in x:1-2, y:0-1; overlaps R2 in x:1-2, y:0-1)
    // Union is essentially L-shape plus extension.
    // Let's rely on the code.
    // Example 1 from LeetCode: {{0,0,2,2},{1,0,2,3},{1,0,3,1}} -> Output 6
    cout << "Test Case 1: " << sol.rectangleArea(rects1) << endl; // Expected: 6

    // Test Case 2: Disjoint
    // (0,0,1,1) -> 1
    // (2,2,3,3) -> 1
    // Total = 2
    vector<vector<int>> rects2 = {{0,0,1,1}, {2,2,3,3}};
    cout << "Test Case 2: " << sol.rectangleArea(rects2) << endl; // Expected: 2
    
    // Test Case 3: Complete Coverage
    // (0,0,3,3), (1,1,2,2)
    // Inner fits inside outer. Total area = area of outer = 9.
    vector<vector<int>> rects3 = {{0,0,3,3}, {1,1,2,2}};
    cout << "Test Case 3: " << sol.rectangleArea(rects3) << endl; // Expected: 9

    return 0;
}