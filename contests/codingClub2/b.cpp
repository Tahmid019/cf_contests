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


vector<string> bel_20 = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> tens = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string n2w(int num) {
    if (num < 20) return bel_20[num];
    if (num < 100) return tens[num / 10] + (num % 10 ? " " + bel_20[num % 10] : "");
    if (num < 1000) return bel_20[num / 100] + " hundred" + (num % 100 ? " " + n2w(num % 100) : "");
    return "";
}

string recurr(ll n, string s) {
    while (n--) {
        string news = n2w(s.length());
        if(s == news) break;
        s = news;
    }
    return s;
}

void solve() {
    ll n;
    cin >> n;
    if(n > 1000){
        cout << "four" << endl;
        return;
    }
    string s = n2w(n);
    string res = recurr(n, s);
    cout << res << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}