#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    if (!(cin >> input)) {
        cerr << "Failed to read input!" << endl; // Debugging message
        return 1; // Indicate error
    }
    cout << "Processed: " << input << endl;
    return 0;
}
