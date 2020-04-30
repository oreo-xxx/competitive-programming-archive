#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; ++i){
        cin >> A[i] >> B[i];
    }

    vector<ll> C(N+1, 0); // 番兵C[N] = 0
    for (int i = N-1; i >= 0; --i) {
        A[i] += C[i+1];
        ll amari = A[i] % B[i];
        ll need = 0;
        if (amari != 0){
            need = B[i] - amari;
        }
        C[i] = C[i+1] + need;
    }
    cout << C[0] << endl;
    return 0;
}
