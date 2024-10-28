#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countSubstrings(const string& s, int k) {
    int n = s.length();
    int total_valid_substrings = 0;

    // Iterate through all possible starting points of the substring
    for (int start = 0; start < n; ++start) {
        // Initialize character count array for the current substring
        vector<int> char_count(26, 0);

        // Expand the substring from `start` to `end`
        for (int end = start; end < n; ++end) {
            // Increment count for the current character in the substring
            char_count[s[end] - 'a']++;

            // Check if any character in char_count meets the condition of >= k
            bool at_least_k = false;
            for (int count : char_count) {
                if (count >= k) {
                    at_least_k = true;
                    break;
                }
            }

            // If at least one character meets the condition, increment the count
            if (at_least_k) {
                total_valid_substrings++;
            }
        }
    }

    return total_valid_substrings;
}

int main() {
    // Example usage
    string s1 = "abacb";
    int k1 = 2;
    cout << countSubstrings(s1, k1) << endl;  // Output: 4

    string s2 = "abcde";
    int k2 = 1;
    cout << countSubstrings(s2, k2) << endl;  // Output: 15

    return 0;
}
