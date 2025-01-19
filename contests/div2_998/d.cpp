/*
    Author: Tahmid Choudhury
    Scholar ID: 2312184
*/
#include<bits/stdc++.h>


using namespace std;

#define tahmid                          \
    ios_base::sync_with_stdio(false);   \
    cin.tie(NULL);

#define pf push_front
#define pb push_back
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
#define vdb vector<double>
#define vldb vector<long double>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vpdb vector<pair<double, double>>
#define vpci vector<pair<char, int>>
#define vpic vector<pair<int, char>>
#define vpcll vector<pair<char, long long>>
#define vpllc vector<pair<long long, char>>

#define forn(i,n) for(long long i = 0; i<n; i++)
#define rep(var, start, end) for(long long var = start; var < end; var++)

#define ff first
#define ss second

#define apriority priority_queue<long long, vector<long long>, greater<long long>>
#define dpriority priority_queue<long long>

#define inpur(var, n)               \
    for(long long i = 0; i<n ; i++) \
    {                               \
        cin >> var[i];              \
    }    

/*======================================= TEMPLATE ENDS ============================================================================================================================================================================================================================================================================================*/





void solve()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<vector<ll>> vis(n+1, vector<ll>(n+1, 0)), gr(n+1, vector<ll>(n+1, 0)), t;
    forn(i, m1){
        ll x, y;
        cin >> x >> y;
        vis[x][y] = 1;
        vis[y][x] = 1;
        t.pb({x,y});
    }
    ll cnt = 0;
    forn(i, m2){
        ll x, y;
        cin >> x >> y;
        if(vis[x][y] == 0) cnt++;
        else gr[x][y] = 1;
    }
    for(auto tt:t){
        if(gr[tt[0]][tt[1]] == 0) cnt++;
    }
    cout << cnt << endl;
}

int main()
{
    tahmid
    ll tt; cin >> tt;
    // ll tt = 1;
    while(tt--)
    {
        solve();
    }

    return 0;
}