#include<iostream>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        float a = (n-1) / 4;
        float b = (n-3) / 4;

        if(a - b < 0.5)
            cout << "Kosuke" << endl;
        else
            cout << "Sakurako" << endl;

    }

    return 0;
}