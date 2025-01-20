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
    ll n, m;
    cin >> n >> m;

    vll a(n), b(m);
    // multiset<ll> ma, mb;
    unorderd_map<ll, ll> mp;
    forn(i, n){
        cin >> a[i];
        // ma.insert(a[i]);
        mp[a[i]]=1;
    }
    int f = 0;
    forn(i, m){
        cin >> b[i];
        if(mp[b[i]] != 1) f = 1;
    }

    if(n < m){
        cout << "NO" << endl;
        return;
    }
    if(n == m){
        if(f == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll cnt = 0;
    ll idx = 0;
    forn(i, n){
        if(idx >= m) break;
        if(a[i] == b[idx]){
            idx++;
            continue;
        }
        ll s = a[i];
        if(i+1 != n){
            s += a[i+1];
        }
        if(s < b[idx]){
            idx++;
        }else if(s == b[idx]){
            idx += 2;
            cnt++;
        }else{
            cout << "NO" << endl;
            return;
        }

    }
    if((n - cnt) == m){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
   
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