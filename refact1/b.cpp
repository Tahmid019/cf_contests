#include <iostream>
#include <vector>
#define ll long long
#define db double
#define dbl long double

using namespace std;



void solve() {
    ll n; cin >> n;
    string s, r; cin >> s >> r;
    vector<char> cc;
    int i = 0;
    for(auto c:s){
        cc.push_back(c);
        while(cc.size() >= 2 && cc[cc.size()- 2]!=cc[cc.size()-1] && i < n-1){
            char rr= r[i++];
            cc.pop_back(); cc.pop_back();
            cc.push_back(rr);
        }
    }
    if(i == n-1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve(); 
    }

    return 0;
}


