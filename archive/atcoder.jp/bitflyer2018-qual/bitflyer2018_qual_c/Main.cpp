#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N, D;
    cin >> N >> D;
    vector<long long> X(N);
    for (int i = 0; i < N; ++i) cin >> X[i];

    vector<long long> L(N), R(N);
    int left = 0, right = 0;
    for (int mid = 0; mid < N; ++mid) {
        while (right < N && X[right] - X[mid] <= D) ++right;
        while (left < mid && X[mid] - X[left] > D) ++left;
        R[mid] = right - 1;
        L[mid] = left;
    }

    long long res = 0;
    for (long long mid = 0; mid < N; ++mid){
        res += (R[mid] - mid) * (mid - L[mid]);
    }

    for (long long left = 0; left < N; ++left){
        res -= (R[left] - left) * (R[left] - left - 1) / 2;
    }
    cout << res << endl;
    return 0;
}
