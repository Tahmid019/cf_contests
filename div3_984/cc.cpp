#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<string> res;

    while (t--) {
        string s;
        int q;
        cin >> s >> q;
        int n = s.size();
        
        set<int> has_1100;
        for (int i = 0; i <= n - 4; ++i)
            if (s.substr(i, 4) == "1100")
                has_1100.insert(i);

        while (q--) {
            int i, v;
            cin >> i >> v;
            --i;

            if (s[i] != '0' + v) {
                for (int j = max(0, i - 3); j <= min(n - 4, i); ++j)
                    if (s.substr(j, 4) == "1100")
                        has_1100.erase(j);

                s[i] = '0' + v;

                for (int j = max(0, i - 3); j <= min(n - 4, i); ++j)
                    if (s.substr(j, 4) == "1100")
                        has_1100.insert(j);
            }
            res.push_back(has_1100.empty() ? "NO" : "YES");
        }
    }

    for (const string& r : res)
        cout << r << "\n";

    return 0;
}