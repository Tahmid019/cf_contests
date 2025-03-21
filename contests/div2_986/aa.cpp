#include <iostream>
#include <vector>
#define ll long long
#define db double
#define dbl long double

using namespace std;



void solve() {
    ll n, a, b; cin >> n >> a >> b ;
    string s; cin >> s;
    ll x =0, y = 0;
    vector<pair<int, int>> mp(n);
    
    for(int i = 0; i<n; i++){
        if(s[i] == 'N') y++;
        else if(s[i] == 'E') x++;
        else if(s[i] == 'S') y--;
        else if(s[i] == 'W') x--;
        mp[i] = {x, y};
        if(x == a && y == b){
            cout << "YES" << endl;
            return;
        }
    }
    if(x == 0 && y == 0){
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i<n; i++){
        int dx = mp[i].first;
        int dy = mp[i].second;
        bool canReach = false;

        if(x!=0 && (a - dx)%x == 0 && (a - dx)/x >= 0) {  
            canReach = (y == 0)||((b - dy)% y == 0 &&(b - dy) / y >= 0);
        } 
        else if(y != 0 && (b - dy) % y == 0 && (b - dy) / y >= 0) {  
            canReach = (x == 0)||((a - dx) % x == 0 && (a - dx) / x >= 0);
        }

        if(canReach) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve(); 
    }

    return 0;
}


