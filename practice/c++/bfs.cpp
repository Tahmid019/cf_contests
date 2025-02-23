#include<bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<ll, vector<ll>> adList;
unordered_map<ll, ll> level, vis, vals;

void bfs(ll vertex){
    queue<ll> q;
    q.push(vertex);

    while(!q.empty()){
        ll curr_vertex = q.front(); q.pop();
        vis[curr_vertex] = 1;
        cout << curr_vertex << " = " << vals[curr_vertex] << " | level = " << level[curr_vertex] << endl;;
        
        for(auto child : adList[curr_vertex]){
            if(vis[child] == 1) continue;
            q.push(child);
            level[child] = level[vertex] + 1;
        }
    }
}

int main(){

    ll v, e;
    cin >> v >> e;
    for(ll i  = 1; i <= v; i++){
        ll idx;
        cin >> idx;
        cin >> vals[idx];

    }

    while(e--){
        ll a, b;
        cin >> a >> b;
        adList[a].push_back(b);
        adList[b].push_back(a);
    }

    bfs(1);

    return 0;
}