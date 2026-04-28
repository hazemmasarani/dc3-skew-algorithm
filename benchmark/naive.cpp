#include <bits/stdc++.h>

using namespace std;


std::vector<int> build_suffix_array_naive(const std::vector<int> &s) {
    int n = s.size();

    std::vector<int> sa(n);
    for (int i = 0; i < n; i++) {
        sa[i] = i;
    }

    std::sort(sa.begin(), sa.end(), [&](int a, int b) {
        int n = s.size();

        int result = 0; // store comparison result

        // Force full scan of both suffixes
        for (int i = 0; i < n; i++) {
            int ca = (a + i < n) ? s[a + i] : -1;
            int cb = (b + i < n) ? s[b + i] : -1;

            if (result == 0 && ca != cb) {
                result = (ca < cb) ? -1 : 1;
            }
        }

        return result < 0;
    });

    return sa;
}

std::vector<int> generate_random_string(const std::vector<int>& input, int n) {
    static std::mt19937 gen(std::random_device{}());  // seeded once

    std::vector<int> result;
    result.reserve(n);

    std::uniform_int_distribution<> dist(0, input.size() - 1);

    for (int i = 0; i < n; ++i) {
        result.push_back(input[dist(gen)]);
    }

    return result;
}

std::vector<int> generate_1_to_n(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }
    return v;
}

int main() {
    
    vector<int> str_length = {1000, 10000, 100000};
    vector<int> alphabet_length = {4, 8, 16, 32, 64, 128, 256};
    int runs = 100;

    ofstream("./logs/latency_naive.log", ios::trunc).close();

    ofstream log_file("./logs/latency_naive.log");

    log_file << "str_len,alph,run,latency_ms\n";

    for (int str_len : str_length) {
        for (int alph : alphabet_length) {

            
            for (int i = 0; i < runs; ++i) {
                // generate alphabet once (good)
                vector<int> alph_vec = generate_1_to_n(alph);

                // generate text OUTSIDE timing of SA
                vector<int> text = generate_random_string(alph_vec, str_len);

                auto start = chrono::high_resolution_clock::now();

                auto sa = build_suffix_array_naive(text);

                auto end = chrono::high_resolution_clock::now();

                double latency = chrono::duration<double, milli>(end - start).count();

                // log result
                log_file << str_len << ","
                         << alph << ","
                         << i << ","
                         << latency << "\n";

                cout     << str_len << ","
                         << alph << ","
                         << i << ","
                         << latency << "\n";
            }
        }
    }

    log_file.close();

    return 0;
}