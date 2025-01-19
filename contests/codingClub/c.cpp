/*
    Author: Tahmid Choudhury
    Scholar ID: 2312184
*/
#include<bits/stdc++.h>


using namespace std;

#define tahmid                          \
    ios_base::sync_with_stdio(false);   \
    cin.tie(NULL);

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
ll cal(ll _max, ll n){
    ll t = _max*2;
        ll k = n/t;
        ll m = n - k*t;
        return k*_max+ m;
}

void solve()
{
    ll n;
    cin >> n;
    if(n==1){
        cout << 1 << endl;
        return;
    }
    int f = 0;
    vll _max;
    for(ll i = 2; i*i <= n ; i++){
        if(n%i == 0){
            f = 1;
            _max.pb(i);
            if(i != n/i){
                _max.pb(n/i);
            }
        }   
    }

    if(f == 1){
        ll ans = 0;
        for(ll i = 0; i<_max.size(); i++){
            ans = max(ans, cal(_max[i], n));
        }
        cout << ans << endl;
    }else{
        cout << n << endl;
    }

}

int main()
{
    tahmid
    ll tt; cin >> tt;
    while(tt--)
    {
        solve();
    }

    return 0;
}