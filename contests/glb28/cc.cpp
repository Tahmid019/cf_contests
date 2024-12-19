/*
    Author: Tahmid Choudhury
    Scholar ID: 2312184
*/
#include<bits/stdc++.h>


using namespace std;

#define tahmid                          \
    ios_base::sync_with_stdio(false);   \
    cin.tie(NULL);

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



void solve() {
    string s;
    cin >> s;


    string tm;
    pair<int, int> pr, cr;

    for(int i = 0; i< s.size(); i++){
        if(s[i] == '1'){
            tm = s.substr(i);
            pr = {i, s.size() - 1};
            break;
        }
    }

    if(tm.empty()){
        cout << "1 1 1 1" << endl;
        return;
    }

    int m = 0, n = 0;

    for(int i = 0; i <tm.size();i++){
        if(tm[i] == '0'){
            n = i;
            m = tm.size() - i;
            break;
        }
    }

    if(m == 0){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                cr = {i, i};
                break;
            }
        }
    }else{
        cr = {0, 0};
        string ans = tm;

        for(int i=0; i + m <=s.size(); i++){
            string now = tm;
            for(int j = i; j < i + m; j++)
                now[j - i + n] = ((now[j - i + n] - '0')^(s[j] - '0')) + '0';

            if(now > ans){
                ans = now;
                cr = { i, i + m - 1 };
            }
        }
    }

    cout << pr.first + 1 << ' ' << pr.second + 1 << ' ' << cr.first + 1 << ' ' << cr.second + 1 << endl;
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