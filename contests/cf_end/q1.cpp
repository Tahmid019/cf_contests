#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <fstream>

using namespace std;

void find_min_speed(int T, const vector<vector<pair<int, int>>> &test_cases, ofstream &output_file) {
    for (int t = 0; t < T; ++t) {
        int N = test_cases[t].size();
        double v_min = -numeric_limits<double>::infinity();  
        double v_max = numeric_limits<double>::infinity();  
        
        for (int i = 0; i < N; ++i) {
            int A_i = test_cases[t][i].first;
            int B_i = test_cases[t][i].second;
            int station_distance = i + 1;

            if (A_i > 0) {
                v_max = min(v_max, station_distance / static_cast<double>(A_i)); 
            }
            v_min = max(v_min, station_distance / static_cast<double>(B_i));     
        }

        if (v_min <= v_max) {
            output_file << "Case #" << t + 1 << ": " << fixed << setprecision(6) << v_min << "\n";
        } else {
            output_file << "Case #" << t + 1 << ": -1\n";
        }
    }
}

int main() {
    ifstream input_file("input.txt");
    ofstream output_file("output.txt");
    
    if (!input_file.is_open() || !output_file.is_open()) {
        cerr << "Error: Could not open input/output file." << endl;
        return 1;
    }

    int T;
    input_file >> T;
    
    vector<vector<pair<int, int>>> test_cases(T);
    
    for (int t = 0; t < T; ++t) {
        int N;
        input_file >> N;
        test_cases[t].resize(N);
        
        for (int i = 0; i < N; ++i) {
            int A_i, B_i;
            input_file >> A_i >> B_i;
            test_cases[t][i] = {A_i, B_i};
        }
    }

    find_min_speed(T, test_cases, output_file);
    
    input_file.close();
    output_file.close();
    
    return 0;
}
