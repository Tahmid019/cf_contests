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


void solve() {
    ll n, k;
    cin >> n >> k;
    stack<ll> a;
    vll aa(n);
    unordered_map<ll, ll> b;
    ll _min = INT_MAX;

    for(ll i =0; i < n; i++){
        ll x = 0;
        cin >> x;
        a.push(x);
        aa[i] = x;
    }
    if(k == 0){
        sort(aa.bn, aa.en);
        cout << aa[0]*n << endl;
        return;
    }
    for(ll i =0 ; i<n ; i++){
        ll x; cin >> x;
        b[x]++;
        _min = min(_min, x);
    }

    // sort(a.be, a.en);
    ll j = a.size() - k;
    while(j--){
        // ll x = a.top();
        a.pop();
    }
    ll ak = a.top();
    if(_min <=0){
        cout << ak*n << endl;
        return;
    }
    ll sum = 0;
    for(auto it: b){
        
        sum = 0;
        ll tem = 0;
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