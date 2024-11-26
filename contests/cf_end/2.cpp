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
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n ; i++){
            cin >> a[i];
        }
        int k = n;
        for(int i = 0; i<n; i++){
            int s = i;
            for(int j = i + 1; j<n; j++){
                if(a[j] > a[i]){
                    s++;
                }
            }
            k = min(k,s);
        }
        cout << k << endl;
        
    }
    
    return 0;
}
