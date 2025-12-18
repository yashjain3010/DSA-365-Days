#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<string, int> map;
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;

        int n = words[0].size();
        map.clear();

        // Populate the frequency map of required words
        for(auto it : words){
            map[it]++;
        }

        // We iterate with different offsets (0 to word_len-1)
        // This ensures we cover all possible starting alignments
        for(int offset = 0 ; offset < n ; offset++){
            int size = 0; // Counts number of valid words currently in window
            unordered_map<string, int> seen;

            // Step through string in chunks of size 'n' (word length)
            for(int i = offset ; i + n <= s.size() ; i += n){
                string sub = s.substr(i, n);

                auto itr = map.find(sub);

                // Case 1: Word is not in the required list
                if(itr == map.end()){
                    seen.clear();
                    size = 0;
                    continue;
                }

                // Case 2: Word is valid
                ++seen[sub];
                ++size;

                // Case 3: Word count exceeds required count
                // Shrink window from the left until count becomes valid
                while(seen[sub] > itr -> second){
                    // Identify the word leaving the window from the left
                    // Formula: current_index - (words_in_window - 1) * word_len
                    string first = s.substr(i - (size - 1) * n, n);
                    --seen[first];
                    --size;
                }

                // If window size matches total number of words, we found a result
                if(size == words.size()){
                    ans.push_back(i - (size - 1) * n);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard Example
    // s = "barfoothefoobarman", words = ["foo", "bar"]
    // "barfoo" (idx 0) and "foobar" (idx 9) are valid
    string s1 = "barfoothefoobarman";
    vector<string> words1 = {"foo", "bar"};

    cout << "Test Case 1:" << endl;
    cout << "String: " << s1 << endl;
    cout << "Words: [ ";
    for(const string& w : words1) cout << w << " ";
    cout << "]" << endl;
    
    vector<int> result1 = sol.findSubstring(s1, words1);
    
    cout << "Indices: [ ";
    for(int idx : result1) cout << idx << " ";
    cout << "]" << endl;
    cout << "-----------------" << endl;

    // Test Case 2: Overlap Example
    // s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
    // Expected: [] (Because "good" is repeated 3 times in s, but only allowed once? 
    // Wait, words has "word" twice, "good" once. String has "good" x3. No valid match.)
    string s2 = "wordgoodgoodgoodbestword";
    vector<string> words2 = {"word", "good", "best", "word"};

    cout << "Test Case 2:" << endl;
    cout << "String: " << s2 << endl;
    cout << "Words: [ ";
    for(const string& w : words2) cout << w << " ";
    cout << "]" << endl;

    vector<int> result2 = sol.findSubstring(s2, words2);

    cout << "Indices: [ ";
    for(int idx : result2) cout << idx << " ";
    cout << "]" << endl;

    return 0;
}