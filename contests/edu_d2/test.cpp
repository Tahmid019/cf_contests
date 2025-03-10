#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;

    unordered_map<int, int> visited;
    int pos = x, count = 0;

    for (int time = 0; time < k; time++) {
        if (visited.count(pos)) {
            // We found a cycle, so we calculate the remaining occurrences directly
            int cycle_length = time - visited[pos];
            int remaining_cycles = (k - time) / cycle_length;
            count += count * remaining_cycles;
            break;
        }
        visited[pos] = time;

        for (char c : s) {
            pos += (c == 'R') ? 1 : -1;
            if (pos == 0) {
                count++;
                time++;
                if (time >= k) break; // Stop when we reach k seconds
                pos = x; // Reset position
            }
        }
    }
    cout << count << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
