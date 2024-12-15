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


void qsolve(){
    ll x;
    cin >> x;

}


void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    vll a(n), b(m);
    inpur(a, n);
    inpur(b, m);
    vector<vector<ll>> grid(n, vector<ll>(m));
    unordered_map<ll, ll> mp;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            grid[i][j] = a[i]*b[j];
            mp[grid[i][j]] = 1;
            sum += grid[i][j];
        }
    }
    cout << sum << endl;

    while(q--){
        ll x;
        cin >> x;

        if(x == sum){
            if(mp[0] == 1){
                cout << "YES" << endl;
                continue;
            }else{ 
                cout << "NO" << endl;
                continue;
            }
        }else{
            ll k = x - sum;
            if(mp[k] == 1){
                cout << "YES" << endl;
                continue;
            }
            else{
                cout << "NO" << endl;
                continue;
            }
        }
    }
}



int main()
{
    tahmid
    ll tt = 1;
    while(tt--)
    {
        solve();
    }
    

    return 0;
}