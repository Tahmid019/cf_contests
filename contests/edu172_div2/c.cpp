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
    ll n, k; cin >> n >> k;
    string s; cin >> s;

    vector<pair<int, int>> mp;
    int f = 0;
    ll a = 0, i;
    for(i = 1; i< n; i++){
        if(s[i] != s[i-1] && s[i] == '1'){
            string t = s.substr(a, i-a);
            ll z = 0, o = 0;
            for(auto c : t){
                if(c == '0') z++;
                else o++;
            }
            mp.push_back({z,o});
            a = i;
        }
    }
    string t = s.substr(a, i-a);
    ll z = 0, o = 0;
    for(auto c : t){
        if(c == '0') z++;
        else o++;
    }
    mp.push_back({z,o});
    cout << mp.size() << endl;
    

    ll sum = 0;
    for(int i = 0; i < mp.size(); i++){
        cout << mp[i].ff << " " << mp[i].ss << endl; 
        sum += mp[i].ss*i - mp[i].ff*i;
        cout << sum << endl;;
    }
    // cout << endl;
    if(sum >=  k){
        cout << mp.size() << endl;
        return;
    }
    cout << -1 << endl;
    
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