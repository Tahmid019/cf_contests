

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cnt1543(const vector<int>& lr) {
    int cnt = 0;
    int len = lr.size();
    if(lr[len-1] == 1 && lr[0] == 5 && lr[1] == 4 && lr[2] == 3) cnt++;
    if(lr[len-2] == 1 && lr[len-1] == 5 && lr[0] == 4 && lr[1] == 3) cnt++;
    if(lr[len-3] == 1 && lr[len-2] == 5 && lr[len-1] == 4 && lr[0] == 3) cnt++;
    for(int i = 0; i <= len - 4; i++) {
        if(lr[i] == 1 && lr[i + 1] == 5 && lr[i + 2] == 4 && lr[i + 3] == 3) cnt++;
    }
    return cnt;
}

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>> mat(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        string row;cin >> row;
        for(int j = 0; j < m; j++) mat[i][j] = row[j] - '0';
    }

    int tcnt = 0,top = 0, l = 0, btm = n - 1, r = m - 1;

    while(top <= btm && l <= r){
        
        vector<int> lr;

        for(int j = l; j <= r; j++) lr.push_back(mat[top][j]);
        for(int i = top + 1; i <= btm; i++) lr.push_back(mat[i][r]);
        if(top < btm) for(int j = r - 1; j >= l; j--) lr.push_back(mat[btm][j]);
        if(l < r) for(int i = btm - 1; i > top; i--) lr.push_back(mat[i][l]);
        
        // cout<<endl;
        // for(auto i:lr) cout << i << " ";
        // cout << endl;
        // cout << endl;

        tcnt += cnt1543(lr);

        top++;
        l++;
        btm--;
        r--;
    }

    cout << tcnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
