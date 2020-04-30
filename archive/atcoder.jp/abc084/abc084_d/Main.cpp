#include <bits/stdc++.h>

using namespace std;
int main() {
    const int MAX = 100001;
    vector<bool> is_prime(MAX);
    for (int i = 2; i < MAX; ++i) {
        is_prime[i] = true;
    }

    for (int i = 2; i < MAX; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i*2; j < MAX; j += i) is_prime[j] = false;
    }

    vector<int> a(MAX);
    for (int i = 0; i < MAX; ++i) {
        if (is_prime[i] && is_prime[(i+1)/2]) a[i] = 1;
    }

    vector<int> s(MAX+1, 0);
    for (int i = 0; i < MAX; ++i) s[i+1] = s[i] + a[i];

    int q; cin >> q;
    for(int i = 0; i < q; ++i){
        int l, r; cin >> l >> r;
        cout << s[r+1] - s[l] << endl;
    }
    return 0;

}