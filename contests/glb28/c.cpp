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

int check(string prev, string curr){
    ll sz = prev.size();
    for(int i = 0; i<sz; i++){
        if(prev[i]!= curr[i]){
            if(prev[i] == '1' && curr[i] == '0') return 0;
            else return 1;
        }
    }
    return 0;
}


int check2(string prev, string s, int k){
    ll cnt = 0;
    for(int i = 0; i < prev.size(); i++){
        if(prev[prev.size() - i - 1] != s[s.size() - k + i]) cnt = cnt*10 +1;
        else cnt = cnt*10 + 0;
    }
    return cnt;
}

void solve()
{
    string s;
    cin >> s;
    
    int size = s.size();
    ll i = 0; 
    for(; i < size; i++){
        if(s[i] == '0') break;
    }
    if(i == size) i--;
    // cout << i << endl;
    ll k = i;
    size = size - i;
    // cout << size << endl;
    string prev = s.substr(0, size);
    int pr = check2(prev,s, k);
    string curr;
    pair<int, int> mx;
    mx = {0, size};
    for(i = 1; i<k; i++ ){
        curr = s.substr(i, i + size);
        // cout << prev << " " << curr << endl;
        // int j = check(prev, curr);
        // if(j == 1){
        //     mx = {i, i + size};
        // }

        int cr = check2(curr, s, k);
        cout << curr << endl;
        if(pr < cr){
            mx = {i, i + size};
            pr = cr;
        }
        cout << pr << endl;
    }
    cout << "1 " << s.size()<< " " <<  mx.ff + 1 << " " << mx.ss << endl;
    // cout << "====" << endl;
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