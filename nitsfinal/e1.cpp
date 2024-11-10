#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ll long long
#define db double
#define dbl long double

using namespace std;

const int MOD = 998244353;
void solve() {
    int n, m;cin>>n>> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    vector<vector<int>> b(n);
    for (int i = 0; i < n; ++i) {
        int k = min(a[i] + 1, m + 1);
        b[i].resize(k);
        for (int j = 0; j < k; ++j)cin >> b[i][j];
    }
    vector<int> dp(m + 1, INT_MAX);
    dp[0] = 0; 
    
    for (int i = 0; i < n; ++i) {
        vector<int> ndp(m + 1, INT_MAX);
        int _items = min(a[i], m);
        for (int j = 0; j <= _items; ++j) {
            int cost = b[i][j];
            for (int x = 0; x <= m - j; ++x) {
                if (dp[x] != INT_MAX) {
                    ndp[x + j] = min(ndp[x + j],(dp[x] + cost) % MOD);
                }
            }
        }
        dp = ndp;
    }
    cout << (dp[m] == INT_MAX ? -1 : dp[m]) << endl;
}

int main() {
    int t; cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}
