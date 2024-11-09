//HIRAK RAJBONSHI 2312020

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "debug.h"
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#define ll long long
#define int long long

void solve(int __tt) {
    int n, m, r1, r2; cin>>n>>m>>r1>>r2;
    if(n > m) swap(n, m);
    if(r1 > r2) swap(r1, r2);
    int d1 = 2*r1+1;
    int d2 = 2*r2+1;
    int maxX = m-r2;
    int maxY = n-r2;
    int minX = r2+1;
    int minY = r2+1;
    if(d2 > m && cout << "-1\n") return;
    int sum = (d1+1+r2+1)+(r1+1);
    int ans = (r1+1<<1) + sum;
    int x = d1+1+r2+1;
    int y = r1+1;
    if(r2+1 >= d1+r1+1) {
        ans = (r1+1<<1)+(r2+1<<1);
        x = r2+1;
        y = r2+1;
    }
    debug(x)
    debug(y)
    
    debug(maxX)
    debug(maxY)
    debug(sum)
    if(x > maxX) {
        y = x+y-maxX;
        x = maxX;
    }
    debug(x)
    debug(y)
    if(y > maxY) {
        x = x+y-maxY;
        y = maxY;
    }
    debug(x)
    debug(y)
    if(y < minY) {
        x = x+y-minY;
        y = minY;
    }
    if(x > maxX || y > maxY || x < minX || y < minY || sum > x+y) {
        cout << "-1\n";
        return;
    }


    cout << ans << "\n";


}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _TEST = 1;
    cin>>_TEST; 
    for(int _ = 1; _ <= _TEST; _++) {
        solve(_);
    }
        
}