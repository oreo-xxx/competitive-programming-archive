#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//
ll N;
vector<ll> A;

bool solve() {
    ll sum = 0;
    for (int i = 0; i < N; ++i) sum += A[i];

    // 操作回数(あまりが出る場合NO)
    ll num = sum / (N * (N + 1) / 2);
    if (sum % (N * (N + 1) / 2) != 0){
        return false;
    }

    // 隣接要素の差を考える
    for (int i = 0; i < N; ++i) {
        ll b = A[(i+1)%N] - A[i] - num;
        if (b % N != 0 || b > 0){
            return false;
        }
    }
    return true;
}


int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> N;
    A.resize(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    if (solve()){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
