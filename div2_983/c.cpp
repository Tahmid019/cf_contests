#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int _min = INT_MAX;
        int _max = INT_MIN;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            _min = min(_min, a[i]);
            _max = max(_max, a[i]);
        }
        if(_max - _min < 3){
            cout << 0 << endl;
        }else{
            int mid = (_max + _min)/2;
            int low_cnt = 0;
            int high_cnt = 0;
            for(int i = 0; i < n; i++){
                if(a[i] < mid) low_cnt++;
                if(a[i] > mid) high_cnt++;
            }
            cout << min(low_cnt, high_cnt) << endl;
        }
    }
    return 0;
}
