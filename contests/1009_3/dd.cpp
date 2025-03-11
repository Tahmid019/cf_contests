#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n), r(n);
        for (int i = 0; i < n; ++i) cin >> x[i];
        for (int i = 0; i < n; ++i) cin >> r[i];
        
        map<int, vector<pair<int, int>>> intervals;
        
        for (int i = 0; i < n; ++i) {
            int xi = x[i], ri = r[i];
            for (int k = 0; k <= ri; ++k) {
                int s_squared = ri * ri - k * k;
                int s = static_cast<int>(sqrt(s_squared));
                int x_start = xi - s;
                int x_end = xi + s;
                
                if (k == 0) {
                    intervals[0].emplace_back(x_start, x_end);
                } else {
                    intervals[k].emplace_back(x_start, x_end);
                    intervals[-k].emplace_back(x_start, x_end);
                }
            }
        }
        
        ll ans = 0;
        for (auto &entry : intervals) {
            auto &vec = entry.second;
            sort(vec.begin(), vec.end());
            vector<pair<int, int>> merged;
            for (auto &p : vec) {
                if (merged.empty()) {
                    merged.push_back(p);
                } else {
                    auto &last = merged.back();
                    if (p.first > last.second) {
                        merged.push_back(p);
                    } else {
                        last.second = max(last.second, p.second);
                    }
                }
            }
            ll total = 0;
            for (auto &p : merged) {
                total += (p.second - p.first + 1);
            }
            ans += total;
        }
        cout << ans << '\n';
    }
    
    return 0;
}