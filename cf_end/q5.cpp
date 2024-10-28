#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

const int MOD = 998244353;

struct TrieNode {
    TrieNode* children[26];
    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a word into the trie and count new nodes
    int insert(const string& word) {
        TrieNode* current = root;
        int newNodes = 0;
        
        for (char ch : word) {
            int index = ch - 'A';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
                newNodes++;
            }
            current = current->children[index];
        }
        return newNodes;
    }
};

// Helper function to generate all possible strings from a wildcard string
void generate_all_strings(const string& pattern, int pos, string& current, vector<string>& results) {
    if (pos == pattern.size()) {
        results.push_back(current);
        return;
    }
    
    if (pattern[pos] == '?') {
        for (char ch = 'A'; ch <= 'Z'; ++ch) {
            current[pos] = ch;
            generate_all_strings(pattern, pos + 1, current, results);
        }
    } else {
        current[pos] = pattern[pos];
        generate_all_strings(pattern, pos + 1, current, results);
    }
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    int T;
    infile >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        infile >> N;

        Trie trie;
        long long total_nodes = 1;  // Root node exists initially

        for (int i = 0; i < N; ++i) {
            string s;
            infile >> s;

            vector<string> all_strings;
            string current(s.size(), ' ');

            // Generate all possible strings from the wildcard pattern
            generate_all_strings(s, 0, current, all_strings);

            // Insert all generated strings into the trie
            for (const string& generated : all_strings) {
                total_nodes = (total_nodes + trie.insert(generated)) % MOD;
            }
        }

        // Write the result for this test case
        outfile << "Case #" << t << ": " << total_nodes << endl;
    }

    infile.close();
    outfile.close();
    
    return 0;
}
