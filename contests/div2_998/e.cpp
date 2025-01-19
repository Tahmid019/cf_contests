#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

// Function to precompute factors for numbers up to max_k
vector<vector<int>> precompute_factors(int max_k) {
    vector<vector<int>> factors(max_k + 1);
    for (int i = 1; i <= max_k; ++i) {
        for (int j = i; j <= max_k; j += i) {
            factors[j].push_back(i);
        }
    }
    return factors;
}

void solve() {
    int t;
    cin >> t;

    vector<pair<int, int>> test_cases(t);
    int max_k = 0;
    for (int i = 0; i < t; ++i) {
        cin >> test_cases[i].first >> test_cases[i].second;
        max_k = max(max_k, test_cases[i].first);
    }

    // Precompute factors for all numbers up to max_k
    vector<vector<int>> factors = precompute_factors(max_k);

    for (auto &[k, n] : test_cases) {
        vector<int> dp(k + 1, 1); // Initial DP: single-element arrays
        vector<int> result(k + 1, 0);

        // Iterate over lengths from 2 to n
        for (int length = 2; length <= n; ++length) {
            vector<int> new_dp(k + 1, 0);
            for (int x = 1; x <= k; ++x) {
                for (int f : factors[x]) {
                    if (f > k) break;
                    new_dp[x] = (new_dp[x] + dp[f]) % MOD;
                }
            }
            dp = new_dp;
        }

        // Store results for x = 1 to k
        for (int x = 1; x <= k; ++x) {
            result[x] = dp[x];
        }

        // Output results for the current test case
        for (int x = 1; x <= k; ++x) {
            cout << result[x] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
