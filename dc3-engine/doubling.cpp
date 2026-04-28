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

vector<int> build_sa_nlogn(vector<int> &text) {
    int n = text.size();

    vector<int> sa(n), rank(n), tmp(n);

    // Initial ranking based on values
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        rank[i] = text[i];
    }

    for (int k = 1; k < n; k <<= 1) {
        // Custom comparator
        auto cmp = [&](int i, int j) {
            if (rank[i] != rank[j])
                return rank[i] < rank[j];

            int ri = (i + k < n) ? rank[i + k] : -1;
            int rj = (j + k < n) ? rank[j + k] : -1;
            return ri < rj;
        };

        sort(sa.begin(), sa.end(), cmp);

        // Recompute temporary ranks
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }

        // Copy back
        rank = tmp;

        // Optimization: stop early if all ranks are unique
        if (rank[sa[n - 1]] == n - 1)
            break;
    }

    return sa;
}

int main() {
    std::vector<int> text = {3, 1, 2, 1, 2, 1};
    std::vector<int> sa_naive = build_suffix_array_naive(text);

    text = {3, 1, 2, 1, 2, 1};
    std::vector<int> sa_db = build_sa_nlogn(text);
    
    cout<<"SA NAIVE:\t";
    for(int elem: sa_naive)
        cout<<elem<<", ";
    
    cout<<endl;
        
    cout<<"SA Doubling:\t";
    for(int elem: sa_db)
        cout<<elem<<", ";

    return 0;
}