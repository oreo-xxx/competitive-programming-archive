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

int sum[2200][2200];


int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    long long H, W, N, M;
    cin >> H >> W >> N >> M;

    vector<string> base(N);
    for (int i = 0; i < N; ++i) cin >> base[i];

    /* N, M それぞれ 2 倍以上になっている部分はつぶして 2 次元いもす */
    long long tH = min(H, N*2), tW = min(W, M*2);
    for (long long i = 0; i < N; ++i) {
        for (long long j = 0; j < M; ++j) {
            if (base[i][j] != '#') continue;
            long long i2 = i + (tH - N) + 1;
            long long j2 = j + (tW - M) + 1;
            sum[i][j] += 1; sum[i2][j] -= 1; sum[i][j2] -= 1; sum[i2][j2] += 1;
        }
    }
    for (int i = 0; i < 2100; ++i)
        for (int j = 0; j < 2100; ++j)
            sum[i][j+1] += sum[i][j];
    for (int j = 0; j < 2100; ++j)
        for (int i = 0; i < 2100; ++i)
            sum[i+1][j] += sum[i][j];

    /* 計算 */
    long long res = 0;
    for (int i = 0; i < tH; ++i) {
        for (int j = 0; j < tW; ++j) {
            if (sum[i][j]) ++res;
        }
    }
    long long left = 2100, right = 2100, top = 2100, bottom = 2100;
    for (long long i = 0; i < N; ++i){
        for (long long j = 0; j < M; ++j) {
            if (base[i][j] == '.') continue;
            left = min(left, j);
            right = min(right, M-1-j);
            top = min(top, i);
            bottom = min(bottom, N-1-i);
        }
    }
    if (left != 2100) {
        res += (H - tH) * (W - right - left);
        res += (W - tW) * (H - top - bottom);
        res -= (H - tH) * (W - tW);
    }
    cout << res << endl;
    return 0;
}
