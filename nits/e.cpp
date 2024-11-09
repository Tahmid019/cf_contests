#include <iostream>
#include <vector>
#include <climits>
#define ll long long
using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        if(s[n-1] == s[0]){
            cout << 0 << endl;
        }else{
            if(s[n-2] == '0' || s[1] == '0'){
                cout << 1 << endl;
            // }else if(s[1] == '1' && s[n-2] == '1'){
            //     cout << 2 << endl;
            // }
            } else{
                cout << 2 << endl;
            }
        }
    }
    return 0;
}
