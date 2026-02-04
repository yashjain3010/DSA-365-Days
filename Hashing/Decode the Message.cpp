#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        // Map to store the substitution table
        unordered_map<char, char> hm;
        char start = 'a';

        // Step 1: Build the Substitution Table
        for(int i = 0 ; i < key.size() ; i++){
            // Ignore spaces and skip characters we've already mapped
            if(key[i] != ' ' && hm.find(key[i]) == hm.end()){
                hm[key[i]] = start;
                start++;
            }
        }

        // Step 2: Decode the Message
        string str = "";
        for(int i = 0 ; i < message.size() ; i++){
            if(message[i] == ' '){
                str += " ";
            } else {
                str += hm[message[i]];
            }
        }
        return str;
    }
};

int main() {
    Solution sol;
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    
    // Expected: "this is a secret"
    cout << "Decoded: " << sol.decodeMessage(key, message) << endl;
    return 0;
}