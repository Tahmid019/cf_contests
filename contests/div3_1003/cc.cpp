#include <bits/stdc++.h>
using namespace std;

bool canSortNonDecreasing(int n, int m, vector<int>& a, vector<int>& b) {
    int b1 = b[0];
    long long prev = -1e18;

    for (int i = 0; i < n; i++) {
        long long option1 = a[i];
        long long option2 = b1 - a[i];

        if (option1 >= prev && option2 >= prev) {
            prev = min(option1, option2);
        } else if (option1 >= prev) {
            prev = option1;
        } else if (option2 >= prev) {
            prev = option2;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);

        for (int& num : a) cin >> num;
        for (int& num : b) cin >> num;

        cout << (canSortNonDecreasing(n, m, a, b) ? "YES" : "NO") << "\n";
    }

    return 0;
}