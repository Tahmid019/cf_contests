#include <iostream>
#include <vector>
#define ll long long
#define db double
#define dbl long double

using namespace std;



void solve() {
    ll n, a, b; cin >> n >> a >> b ;
    string s; cin >> s;
    int x = 0, y = 0;
    bool ff = false;
    int cc = 0;

    while(cc < 100) {
        for(auto c:s) {
            if(c == 'N') y++;
            else if(c == 'W') x--;
            else if(c == 'S') y--;
            else if(c == 'E') x++;
            if(x == a && y == b) {
                ff = true;
                break;
            }
        }
        if(ff) break;
        cc++;
    }
    
    if(ff) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve(); 
    }

    return 0;
}


