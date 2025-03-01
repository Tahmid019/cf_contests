/*
    Author: Tahmid Choudhury
    Scholar ID: 2312184
*/
#include<bits/stdc++.h>


using namespace std;

#define tahmid                          \
    ios_base::sync_with_stdio(false);   \
    cin.tie(nullptr);                   \
    cout.tie(nullptr);

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

const int MAXL = 400001; 

ll check[MAXL], cnt[MAXL], sum[MAXL];

void solve(){
    ll n;
    cin >> n;
    for(ll i = 1; i<=2*n; i++){
        check[i] = 0;
        cnt[i] = 0;
    }
    vpll w(n+1);
    for(ll i = 1; i<= n ; i++){
        cin >> w[i].ff >> w[i].ss;
        if(w[i].ff == w[i].ss){
            check[w[i].ff] = 1;
            cnt[w[i].ff]++;
        }
        // cout << check[w[i].ff] << " ";
    }
    for(ll i = 2; i<= 2*n; i++){
        check[i] += check[i-1];
        // cout << sum[i] << " ";
    }
    // cout << endl;

    for(ll i = 1; i<=n; i++){
        ll a = w[i].ff, b = w[i].ss;
        // cout << a << " " << b << endl;
        ll temp = check[b] - check[a-1];
        // cout << temp << endl;
        if(a == b){
            if(cnt[a] <= 1){
                cout << "1";
            }else{
                cout << "0";
            }
        }else{
            if(temp < b - a + 1){
                cout << "1";
            }else{
                cout << "0";
            }
        }
    }
    cout << endl;

    




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