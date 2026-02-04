#include <iostream>
#include <vector>
#include <numeric> // For std::partial_sum (though manual loop is fine)
#include <algorithm> // For std::max_element

using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // Create a "difference array" for the years 1950 to 2050
        // Index 0 = 1950, Index 100 = 2050
        vector<int> population(101, 0);

        // Mark +1 for birth year and -1 for death year
        for (auto& log : logs) {
            // log[0] is birth year
            population[log[0] - 1950]++;
            // log[1] is death year (person is not alive in this year)
            population[log[1] - 1950]--;
        }

        int maxi = population[0];
        int year = 1950;

        // Calculate the running prefix sum
        // population[i] will store the actual population in year (1950 + i)
        for (int i = 1; i < 101; i++) {
            population[i] = population[i - 1] + population[i];
            
            // Check for a new maximum population
            // The problem asks for the *earliest* year with max population
            if (population[i] > maxi) {
                maxi = population[i];
                year = 1950 + i;
            }
        }
        return year;
    }
};

int main() {
    Solution sol;

    // Test Case 1: [[1993, 1999], [2000, 2010]]
    // Pop: 1 in [1993, 1998]
    // Pop: 1 in [2000, 2009]
    // Max pop is 1, earliest year is 1993
    vector<vector<int>> logs1 = {{1993, 1999}, {2000, 2010}};
    cout << "Input: {{1993, 1999}, {2000, 2010}}\nOutput: " << sol.maximumPopulation(logs1) << endl;

    // Test Case 2: [[1950, 1961], [1960, 1971], [1970, 1981]]
    // Pop: 1 in [1950, 1960]
    // Pop: 2 in [1960, 1960] (one leaves 1961, one joins 1960)
    // Pop: 1 in [1961, 1969]
    // Pop: 2 in [1970, 1970]
    // Max pop is 2, earliest year is 1960
    vector<vector<int>> logs2 = {{1950, 1961}, {1960, 1971}, {1970, 1981}};
    cout << "\nInput: {{1950, 1961}, {1960, 1971}, {1970, 1981}}\nOutput: " << sol.maximumPopulation(logs2) << endl;

    return 0;
}