/*
    Author: Tahmid Choudhury
    Scholar ID: 2312184
*/
#include<bits/stdc++.h>

using namespace std;

#define tahmid \
    ios_base::sync_with_stdio(false); \
    cin.tie(NUll);

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



void solve()
{   
    ll n, st, e;
    cin >> n >> st >> e;
    umlvll adj(n+1);
    forn(i, n-1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vll a(n+1);
    umlvll dp(n+1);
    // cout << "=====" << endl;
    auto dfs = [&](auto &&self, ll u, ll p) -> void {
        a[u] = a[p] + 1;
        // cout << u << endl;
        dp[a[u]].pb(u);
        for(auto v : adj[u]){
            if(v == p) continue;
            self(self, v, u);
        }
    };

    dfs(dfs, e, 0);
    // cout << "=====" << dp.size()<<endl;
    for(ll i = n; i>=1; i--){
        for(auto j : dp[i]) {
            cout << j << " ";
        }
    }
    cout << endl;
}

int main()
{
    tahmid
    ll tt = 1;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}