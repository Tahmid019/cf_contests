#include<bits/stdc++.h>

using namespace std; 


#define ll long long
#define ff first
#define ss second

unordered_map<ll, vector<ll>> adList;
unordered_map<ll, ll> depth;

void dfs(ll v, ll par = -1){
    for(auto child : adList[v]){
        if(par == child) continue;
        depth[child] = depth[v]+1;
        dfs(child, v);
    }
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
    int _max = -1;
    int max_node;
    for(auto& p : depth){
        cout << p.ff << " ";
        if(_max < p.ss){
            _max = p.ss;
            max_node = p.ff;
        }
        p.ss = 0;
    }
    cout << endl;

    dfs(max_node);

    for(auto& p : depth){
        cout << p.ff << " ";
        if(_max < p.ss){
            _max = p.ss;
            max_node = p.ff;
        }
        p.ss = 0;
    }
    cout << endl;
    cout << _max << endl;
    return 0;
}
