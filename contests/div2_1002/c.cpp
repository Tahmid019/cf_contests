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

#define forn(i,n) for(long long i = 0; i<n; i++)
#define rforn(i,n) for(long long i = n-1; i>= 0; i--)
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

#define matin(var, n,m)                       \
    for(long long i = 0; i<n ; i++)         \
    {                                       \
        for(long long j = 0; j<m; j++){     \
            cin >> var[i][j];               \
        }                                   \
    } 





/*======================================= TEMPLATE ENDS ============================================================================================================================================================================================================================================================================================*/

void solve()
{
    ll n;
    cin >> n;
    vvll a(vlv(n,n));
    matin(a,n,n);
    
    vll b;
    forn(i, n){
        ll v = 0;
        for(ll j = n-1; j >= 0; j--){
            if(a[i][j] == 1){
                v++;
            }
            else break;
        }
        b.eb(v);
    }
    sort(b.begin(), b.end());
    
    ll mex = 0;
    for(ll i = 0; i<n; i++){
        // cout << i << " -> " << b[i] << endl;
        if(b[i] >= mex){
            mex++;
        }
    }
    cout << mex << endl;



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