#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> PrefixSum(n+1,0);
        unordered_set<char> vowels = {'a','e','i','o','u'};

        for(int i = 0 ; i < n ; i++){
            PrefixSum[i+1] = PrefixSum[i];
            if(vowels.count(words[i].front()) && vowels.count(words[i].back())){
                PrefixSum[i+1]++;
            }
        }

        vector<int> ans;

        for(auto& query : queries){
            int L = query[0], R = query[1];
            ans.push_back(PrefixSum[R+1]-PrefixSum[L]);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
    vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};

    vector<int> result = sol.vowelStrings(words, queries);

    cout << "Result: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i < result.size() - 1 ? ", " : "");
    }
    cout << "]" << endl;

    return 0;
}