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

void solve()
{
    ll n, m;
    cin >> n >> m ;

    vector<vector<ll>> a(n , vector<ll>(m)), b(n, vector<ll>(m, 0));
    vll row(n, 0), col(m, 0), numr(n,0), numc(m,0);
    ll _max = INT_MIN;
    forn(i, n)
    {
        
        forn(j, m)
        {
            cin >> a[i][j];
            if(a[i][j] == 0){
                numr[i]++;
                numc[j]++;
            }
            if(i == 0 && j == 0){
                row[i] = a[i][j];
                col[j] = a[i][j];

            }else{
                row[i] = row[i-1] + a[i][j];
                col[j] = col[j-1] + a[i][j];
            }
        }
    }

    forn(i, n){
        forn(j, m){
            b[i][j] = max(numr[0], numc[j]);
        }
    }





    forn(i,n){
        _max = max(_max, row[i]);
    }
    forn(i, m){
        _max = max(_max, col[i]);
    }

    string s;
    cin >> s;
    ll i = 0, j = 0;

    while(i < n || j < m)
    {
            ll len = max(row[i], col[j]);
            len = _max - len;
            if(a[i+1,j] == 0){
                
            }
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