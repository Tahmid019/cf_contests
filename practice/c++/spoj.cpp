#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>> level(8, vector<ll>(8, 0)), vis(8, vector<ll>(8, 0));

int getX(string s) {
    return s[0] - 'a';
}

int getY(string s) {
    return s[1] - '1';
}

void clear() {
    for (ll i = 0; i < 8; i++) {
        for (ll j = 0; j < 8; j++) {
            level[i][j] = 0;
            vis[i][j] = 0;
        }
    }
}

vector<pair<ll, ll>> movs = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
};

ll solve(string s1, string s2) {
    int srcX = getX(s1);
    int srcY = getY(s1);
    int destX = getX(s2);
    int destY = getY(s2);

    queue<pair<int, int>> q;
    q.push({srcX, srcY});
    vis[srcX][srcY] = 1;
    level[srcX][srcY] = 0;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;

        for (auto mov : movs) {
            int newx = x + mov.first;
            int newy = y + mov.second;

            if (newx < 0 || newx >= 8 || newy < 0 || newy >= 8 || vis[newx][newy] == 1) 
                continue;

            vis[newx][newy] = 1;
            level[newx][newy] = level[x][y] + 1;
            q.push({newx, newy});

            if (newx == destX && newy == destY) 
                return level[newx][newy];
        }
    }
    return level[destX][destY];
}

int main() {
    ll t = 0;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        clear();
        cout << solve(s1, s2) << endl;
    }
    return 0;
}
