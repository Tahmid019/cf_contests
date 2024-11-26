#include <iostream>
#include <string>
using namespace std;

bool hasSubstr1100(const string& s, int index) {
    for (int i = max(3, index - 3); i <= min((int)s.size() - 1, index + 3); ++i) {
        if (s.substr(i - 3, 4) == "1100") {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int q;
        cin >> q;

        for (int i = 0; i < q; i++) {
            int x, y;
            cin >> x >> y;
            --x; 

            s[x] = '0' + y;

            if (hasSubstr1100(s, x)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
