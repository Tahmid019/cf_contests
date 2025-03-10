/*
    Author: Tahmid Choudhury
    Scholar ID: 2312184
*/
#include<bits/stdc++.h>

using namespace std;

#define tahmid \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define ll long long
#define db double
#define ldb long double
#define ul unsigned long

#define be begin()
#define en end()
#define rbe rbegin()
#define ren rend()
#define asort(vec) sort(vec.begin(), vec.end())
#define dsort(vec) sort(vec.begin(), vec.end(), greater<long long>())

#define vc vector<char>
#define vi vector<int>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vlv(n,m) n, vector<long long>(m)
#define vdb vector<double>
#define vldb vector<long double>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vpdb vector<pair<double, double>>
#define vpci vector<pair<char, int>>
#define vpic vector<pair<int, char>>
#define vpcll vector<pair<char, long long>>
#define vpllc vector<pair<long long, char>>

#define umll unordered_map<long long, long long>
#define umlc unordered_map<long long, char>
#define umlvll unordered_map<long long, vector<long long>>
#define umlvc unordered_map<long long, vector<char>>

#define forn(i,n) for(long long i = 0; i<n; i++)
#define rforn(i,n) for(long long i = n-1; i>= 0; i--)
#define rep(var, start, end) for(long long var = start; var < end; var++)

#define ff first
#define ss second

#define apriority priority_queue<long long, vector<long long>, greater<long long>>
#define dpriority priority_queue<long long>

#define inpur(var, n) \
    for(long long i = 0; i<n ; i++) \
    { \
        cin >> var[i]; \
    }

#define matin(var, n, m) \
    for(long long i = 0; i<n ; i++) \
    { \
        for(long long j = 0; j<m; j++){ \
            cin >> var[i][j]; \
        } \
    }

#define MOD 1000000007

template<typename T>
inline T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }

/*======================================= TEMPLATE ENDS =======================================*/


void bfs(umlvll &tree, umlvll &ck, ll st, ll end, ll n, vll &vis) {
    queue<ll> q;
    q.push(st);
    vis[st] = 1;
    ck[st].pb(st);
    while(!q.empty()) {
        ll curr = q.front();
        q.pop();
        for(auto c: tree[curr]) {
            if(vis[c] == 1) continue;
            vis[c] = 1;
            ck[c]= ck[curr];
            ck[c].pb(c);
            if(c== end) return;
            q.push(c);
        }
    }
}

void solve(){
    ll n, st,end;
    cin >> n>> st >> end;
    umlvll tree;
    vll vis(n + 1, 0);
    forn(i, n - 1){
        ll x, y;
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }

    umlvll ck;
    bfs(tree, ck, st, end, n, vis);

    if(st == end){
        for(ll i= n; i >= 1; i--){
            if(i == end) continue;
            cout << i << " ";
        }
        cout << end << endl;
        return;
    }

    vll path = ck[end];
    for(auto it : path){
        vis[it] = 2;
        cout << it << " ";
    }

    for(ll i= 1; i<= n; i++){
        if(vis[i] == 2) continue;
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}