#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int M = 1e9 + 10;
int n, m;

int arr[N][N], vis[N][N], lev[N][N];

vector<pair<int, int>> movs = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};

bool isnVal(int x, int y){
    return (x < 0 || y < 0 || x >= n || y >= m);
}

int dfs(){
    int _max = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i< n; i++){
        for(int j = 0; j<m; j++){
            _max = max(_max, arr[i][j]);
        }
    }

    for(int i = 0; i< n; i++){
        for(int j = 0; j<m; j++){
            if(_max == arr[i][j]){
                q.push({i, j});
                lev[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    
    int ans = 0;

    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        for(auto mov : movs){
            int curr_x = x + mov.first;
            int curr_y = y + mov.second;
            
            // cout << curr_x << " " << curr_y << endl;
            if(isnVal(curr_x, curr_y)) continue;
            if(vis[curr_x][curr_y] == 1) continue;

            vis[curr_x][curr_y]  = 1;

            q.push({curr_x, curr_y});
        
            lev[curr_x][curr_y] = lev[x][y] + 1;
            ans = max(ans, lev[curr_x][curr_y]);
        }
    }
    return ans;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    cout << dfs() << endl;

}