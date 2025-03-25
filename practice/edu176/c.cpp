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

ll bst(vll a,ll val, ll l, ll r){
    if(l >= r) return l;
    ll m = (l+r)/2;
    if(val == a[m]) return m;
    if(a[m] >  val){
        return bst(a, val, l, m);
    }else{
        return bst(a, val, m+1, r);
    }
}

void solve()
{   
    ll n, m;
    cin >> n >> m;
    vll a(m);
    inpur(a, m);
    asort(a);
    ll sum = 0;
    for(ll i = 1; i < n; i++){
        ll x = m - (lower_bound(a.begin(), a.end(), i) - a.begin());
        ll y = m - (lower_bound(a.begin(), a.end(), n-i) - a.begin());
        // cout << x << " " << y << endl;
        sum += x*y - min(x, y);
    }
    cout << sum << endl;
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

    // vll a = {1,1,1,4,5,6,6,9,9,10,12,19,23,24,45};
    // cout << a.size() << endl;
    // cout << bst(a, 7,0, a.size()-1) << endl;
    // return 0;
}