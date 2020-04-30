#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library

//
int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int n, k;
    cin >> n >> k;
    vector<int> w(n);
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        cin >> w[i] >> p[i];
    }

    double lb = 0.0, ub = 100.0;
    int count = 0;
    while(count < 200){
        double mb = (lb + ub) / 2.0;

        double t[n];
        for(int i = 0; i < n; ++i){
            t[i] = w[i] * (p[i]- mb) / 100.0;
        }
        sort(t, t + n, greater<double>());

        double total = 0;
        for(int i = 0; i < k; ++i){
            total += t[i];
        }
        if(total <= 0){
            ub = mb;
        }
        else{
            lb = mb;
        }

        ++count;
    }

    cout << setprecision(10) << ub << endl;

    return 0;
}

