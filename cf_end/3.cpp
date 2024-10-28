#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fun(const vector<int>& arr) {
    vector<int> lis;
    for (int num : arr) {
        auto pos = upper_bound(lis.begin(), lis.end(), -num);
        if (pos == lis.end()) {
            lis.push_back(-num);
        } else {
            *pos = -num;
        }
    }
    return arr.size() - lis.size();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) cin >> arr[i];
        cout << fun(arr) << endl;
    }
    return 0;
}
