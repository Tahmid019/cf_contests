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

void solve()
{   
    ll n;
    cin >> n;
    vll a(2*n);
    inpur(a, 2*n);

    sort(a.begin(), a.end(), greater<long long>());
    ll l = a[0] - a[1], r = 0;
    for( ll i = 2; i < 2*n; i+=2) {
        r += a[i] - a[i+1];
    }
    // cout << l << "===" << r << endl;
    if(l+r < a[0]) {
        cout << l+r << " ";
        for(ll i = 0; i < 2*n; i+=2) {
            cout << a[i] << " " << a[i+1] << " ";
        }
        cout << endl;
    }else{
        cout << a[0] << " " << l+a[1]<< " " << a[1] << " ";
        for( ll i = 2; i < 2*n; i+=2) {
            cout << a[i] << " " << a[i+1] << " ";
        }
        cout << endl;
    }
    
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