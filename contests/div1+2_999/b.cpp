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
    map<ll, ll> fq;
    vll dd;

    sort(a.begin(), a.end());

    
    for(auto n:a){
        fq[n]++;
        if(fq[n] == 2){
            dd.pb(n);
        }
    }

    if(dd.empty()){
        cout << -1 << endl;
        return;
    }else if(dd.size() > 1){
        cout << dd[0] << " " << dd[0] << " " << dd[1] << " " << dd[1] << endl;
        return;
    }

    ll v = dd[0];

    vll res;
    ll cnt = 2;
    for(auto n : a){
        if(n == v && cnt > 0){
            cnt--;
            continue;
        }
        res.pb(n);
    }

     int f = 0;
     forn(i, res.size()-1){
        if(res[i+1] < res[i] + 2*v){
            cout << v << " " << v << " " << res[i] << " " << res[i+1] << endl;
            f = 1;
            break;
        }
     }

     if(f == 0){
        cout << -1 << endl;
        return ;
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