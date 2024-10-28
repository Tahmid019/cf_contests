#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int fun(map<int , int, greater<int>> mp) {
    int a = 0, b = 0;
    int cnt = 0;
    for(auto m:mp){
        // a = m.first;
        // b = m.second;
        cout << a << " "<< b<< " " << m.first<< " " << m.second<<  " -->" << cnt << endl;
        if(a > m.first){
            // a = m.first;
            // b = m.second;
            if(b < m.second){
                return cnt + b;
            }else{
                cnt+= b - m.second;
            }
            
        }
        a = m.first;
        b = m.second;
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m, r,c;
        cin >> n >> m >> r >> c;
        /*
        k   k 
        k k k 
        */
        long long sum = abs(m - c) + abs(n - r)*abs(m - 1) + abs(n - r)*3;
        //(m - c) + (n - r)*(m - 1 + 3)
        /*
        999999
        999999*999999
        999999*(3 + 1) 
        */
        cout << sum << endl;
        
    }
    
    return 0;
}

