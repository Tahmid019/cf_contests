#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        long long total = 0;
        
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            mp[x] += y;  
            total += y;
        }
        
        if (n >= mp.size()) {
            cout << total << endl;
        } else {
            vector<int> val;
            for (auto& it : mp) {
                val.push_back(it.second);
            }
            sort(val.rbegin(), val.rend()); 
            
            total = 0;
            for (int i = 0; i < n; i++) {
                total += val[i];
            }
            cout << total << endl;
        }
    }
    return 0;
}
