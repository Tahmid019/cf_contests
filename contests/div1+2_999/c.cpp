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
#define vvll vector<vector<ll>>

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

const ll MOD = 998244353;

// ll fun(ll n){
//     ll cnt = 0;
//     while(n%2 == 0){
//         n /= 2;
//         cnt++;
//     }
//     return cnt;
// }

ll area(ll c, ll a, ll b){
    ll ar = ((a+b)/2)*(sqrt((c+ a-b)*(c-a+b)*(a+b-c)*(a+b+c)));
    return ar;
}

// void solve()
// {
//     ll n;
//     cin >> n;
//     vll aa(n);
//     inpur(aa, n);
//     sort(aa.begin(), aa.end());
//     forn(i, n){
//         ll a = aa[i%n], b = aa[(i+1)%n], c = aa[(i+2)%n], d = aa[(i+3)%n];
//         if(a == b){
//             ll ar = area(a, c,d);
//             if(ar < 0) continue;
//             cout << a << " " << b << " " << c << " " << d << endl;
//             return; 
//         }
//     }
//     cout << -1 << endl;
//     return;

// }

void solve(){
    ll n;
    cin >> n;

    vll a(n);
    inpur(a,n);
    
    vvll dp(n+1, vll(2,0));
    dp[0][0] = 1;
    forn(i,n){
        vvll ndp(n+1, vll(2,0));
        forn(lr, i+1){
            forn(prev, 2){
                if(dp[lr][prev] == 0) continue;
                if(lr == a[i]){
                    ndp[lr][0] = (ndp[lr+1][1] + dp[lr][prev])%MOD;
                }
            }
        }
        dp = ndp;
    }

    ll res = 0;
    forn(lr, n+1){
        forn(last, 2){
            res = (res + dp[lr][last])%MOD;
        }
    }
    cout << res << endl;
   
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