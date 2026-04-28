#include <bits/stdc++.h>

using namespace std;


std::vector<int> build_suffix_array_naive(const std::vector<int> &s) {
    int n = s.size();

    std::vector<int> sa(n);
    for (int i = 0; i < n; i++) {
        sa[i] = i;
    }

    // Sort suffix indices
    std::sort(sa.begin(), sa.end(), [&](int a, int b) {
        int n = s.size();
        while (a < n && b < n) {
            if (s[a] != s[b])
                return s[a] < s[b];
            a++;
            b++;
        }
        return a == n; // shorter suffix comes first
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
    
    std::vector<int> text = {3, 1, 2, 1, 2, 1};
    std::vector<int> sa_naive = build_suffix_array_naive(text);
    
    cout<<"SA NAIVE:\t";
    for(int elem: sa_naive)
        cout<<elem<<", ";

    return 0;
}
