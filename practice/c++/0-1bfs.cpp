#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define ob pop_back
#define of pop_front

const int N = 1e5 + 10;
const int M = 1e9 + 10;

vector<pair<int, int>> ad[N];
vector<int> lev(N, M);
int vv, e;
int x, y;

int bfs(){
    deque<int> dq;
    dq.pb(1);
    lev[1] = 0;
    while(!dq.empty()){
        int curr = dq.front(); dq.of();

        for(auto it : ad[curr]){
            int v = it.first;
            int w = it.second;

            if(lev[curr] + w < lev[v]){
                lev[v] = lev[curr] + w;
                if(w == 1){
                    dq.pb(v);
                }else{
                    dq.pf(v);
                }
            }
        }
    }

    return lev[vv] == M ? -1 : lev[vv];
}

int main() {
    cin >> vv >> e;    
    for(int i=0; i<e; i++){
        cin >> x >> y;
        ad[x].push_back({y,0});
        ad[y].push_back({x,1});
    }

    cout << bfs() << endl;

    return 0;
}
