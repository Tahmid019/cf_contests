#include <iostream>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define db double
#define dbl long double

using namespace std;



void solve() {
    ll n; cin >> n;
    // vector<int> a(n);
    ll x;
    map<ll, ll> mp;
    multiset<ll> st;
    for(ll i=0; i<n; i++){
        cin >> x;
        // a[i] = x;
        mp[x] = 1;
        st.insert(x);
    }
    // cout << *st.begin() << endl;
    if(n < 2){
        cout << 0 << " " << 0 << endl;
        return;
    }
    n -= 2;
    bool f = false;
    while(!st.empty()){
        auto i = st.begin();
        ll k = *i;
        st.erase(i);
        
        // cout << "-- " << st.size() << endl;
        // ll p = n%k;
        // if(k == 0) continue;

        if(k != 0 && n%k == 0){
            ll q = n/k;
            // cout << "== " << q << endl;
            if(mp.find(q) != mp.end()){
                cout << k << " " << q << endl;
                f = true;
                break;
            }
        }
    }
    if(!f) cout << 0 << " " << 0 << endl;
    

}

int main(){
    int t; cin >> t;
    while(t--){
        solve(); 
    }

    return 0;
}


