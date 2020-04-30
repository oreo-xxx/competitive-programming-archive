#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

void Gauss(vector<long long> &A) {
    int rank = 0;
    for (int d = 0; d < 60; ++d) {
        int pivot = -1;
        for (int i = rank; i < (int)A.size(); ++i) {
            if (A[i] & (1LL<<d)) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[rank], A[pivot]);
        for (int j = 0; j < (int)A.size(); ++j) {
            if (j == rank) continue;
            if (!(A[j] & (1LL<<d))) continue;
            A[j] ^= A[rank];
        }
        ++rank;
    }
}

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; cin >> N;
    vector<long long> A(N);
    vector<long long> B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    Gauss(A);
    Gauss(B);
    if (A == B) puts("Yes");
    else puts("No");
    return 0;
}

