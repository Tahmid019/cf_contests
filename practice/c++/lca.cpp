#include<bits/stdc++.h>

using namespace std; 


#define ll long long
#define ff first
#define ss second

unordered_map<ll, vector<ll>> adList;
unordered_map<ll, ll> par;

void dfs(ll v, ll p = -1){
    par[v] = p;
    for(auto child : adList[v]){
        if(p == child) continue;
        dfs(child, v);
    }
}

vector<ll> path(ll v){
    vector<ll> ans;
    while(v != -1){
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

    ll v, e;
    cin >> v >> e;

    for(ll i = 0; i< e; i++){
        ll a, b;
        cin >> a >> b;
        adList[a].push_back(b);
        adList[b].push_back(a);
    }

    dfs(1);

    ll x, y;
    cin >> x >> y;
    
    vector<ll> pathx = path(x);
    vector<ll> pathy = path(y);

    ll path_len = min(pathx.size(), pathy.size());
    ll lca = -1;
    for(ll i= 0 ; i < path_len; i++){
        if(pathx[i] != pathy[i]) break;
        lca = pathx[i];
    }

    cout << lca << endl;
    return 0;
}
