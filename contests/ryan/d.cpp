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

#define input(var, n)               \
    for(long long i = 0; i<n ; i++) \
    {                               \
        cin >> var[i];              \
    }    

/*======================================= TEMPLATE ENDS ============================================================================================================================================================================================================================================================================================*/


void solve()
{
   ll n; cin >> n;
   vll a(n);
   input(a, n)
   if(n == 1){
     cout << 0 << endl;
     return;
   }
   if(n == 2 && a[0] > a[1] && abs(a[1] - a[0]) == 1){
     cout << 1 << endl;
     return;
   }

   vector<pair<ll, ll>> res;
   
   for(ll k = n; k >= 0; k--){
        for(ll i = 0; i<k; i++){
            
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