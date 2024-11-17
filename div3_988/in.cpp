#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long

using namespace std;

void solve() {
    ll n;cin>> n;
    if(n < 2){ 
        cout << 0 << " " << 0 << endl;return;
    }
    unordered_map<int, int> freq;
    vector<int> val;
    for(ll i = 0; i < n; i++){
        int x;cin>> x;
        freq[x]++;
        val.push_back(x);
    }

    n -= 2;
    bool f = false;

    for(int k: val) {
        if(k!= 0 && n%k == 0){ 
            ll q= n / k;
            if(freq.find(q) != freq.end()){ 
                cout << k << " " << q << endl;
                f= true;break;
            }
        }
    }

    if(!f) cout << 0 << " " << 0 << endl;
}

int main(){
    int t;cin >> t;
    while(t--) solve();
    return 0;
}
