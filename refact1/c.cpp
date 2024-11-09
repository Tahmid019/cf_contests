#include <iostream>
#include <vector>
#include <climits>

using namespace std;



void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    long long ss = 0;
    long long st = LLONG_MIN;
    long long sd = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        int ai = a[i];
        long long tss;
        if (ai > ss)
            tss = ss + 1;
        else if (ai == ss)
            tss =ss;
        else
            tss = ss - 1;
        long long tt = max(st,(long long)ss);
        long long td = LLONG_MIN;
        if (st != LLONG_MIN)
        {
            if (ai > st)
                td = st + 1;
            else if (ai == st)
                td = st;
            else
                td = st - 1;
        }
        long long td2 = LLONG_MIN;
        if (sd != LLONG_MIN)
        {
            if (ai > sd)
                td2 = sd + 1;
            else if (ai == sd)
                td2 = sd;
            else
                td2 = sd - 1;
        }
        long long temp_sd = max(td, td2);
        ss = tss;
        st = tt;
        sd = temp_sd;
    }
    sd = max(sd, st);
    cout << sd << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve(); 
    }

    return 0;
}


