#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

const int N = 1e3 + 10;
const int M = 1e9 + 10;
int n, k, m, x, y, wt;

vector<pair<int, int>> adList[N];

void reset(){
    for(int i = 0; i < m; i++){
        adList[i].clear();
    }
}

int minTime(int source){
    vector<int> vis(N, 0), dist(N, M);

    set<pair<int, int>> st;
    st.insert({0, source});
    dist[source] = 0;

    int _max = 0;

    while(!st.empty()){
        auto curr = *st.begin(); st.erase(st.begin());
        int curr_val = curr.ss;
        int curr_wt = curr.ff;

        if(vis[curr_val] == 1) continue;
        vis[curr_val] = 1;

        for(auto p : adList[curr_val]){
            int new_val = p.ff;
            int new_wt = p.ss;

            if(dist[curr_val] + new_wt < dist[new_val]){
                dist[new_val] = dist[curr_val] + new_wt;
                st.insert({new_wt, new_val});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(dist[i] == M) return -1;
        _max = max(_max, dist[i]);
    }

    return _max;
}   

void solve(){
    cin >> n >> k >> m;
    while(m--){
        cin >> x >> y >> wt;
        adList[x].pb({y, wt}); 
    }

    cout << minTime(k) << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}