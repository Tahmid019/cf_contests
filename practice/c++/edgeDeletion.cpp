#include<bits/stdc++.h>

using namespace std; 

const int LIM = 1e5;
const int MOD = 1e9 + 7;

#define ll long long
#define ff first
#define ss second

unordered_map<ll, vector<ll>> adList;
unordered_map<ll, ll> vals, subtree;

void dfs(ll v, ll p = -1){
    
    subtree[v] += vals[v];
    for(auto child : adList[v]){
        if(p == child) continue;
        dfs(child, v);
        subtree[v] = subtree[child] + 1;
    }
}

int main(){

    
    ll v, e;
    cin >> v >> e;

    for(ll i =1; i<= v; i++){
        ll idx;
        cin >> idx >> vals[idx];
    }

    for(ll i = 0; i < e ; i++){
        ll a, b;
        cin >> a >> b;
        adList[a].push_back(b);
        adList[b].push_back(a);
    }

    dfs(1);

    ll ans;
    for(ll i = 2; i <= v; i++){
        ll part1 = subtree[i];
        ll part2 = subtree[1] - part1;
        ans = max(ans, (part1*1LL*part2) % MOD);
    }

    cout << ans << endl;

    return 0;
}
