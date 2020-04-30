#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> A;
vector<long long> sum;

int main() {
    cin >> N; 
    A.resize(N); sum.resize(N+1); sum[0] = 0;
    for (int i = 0; i < N; ++i) cin >> A[i], sum[i+1] = sum[i] + A[i];

    long long res = 1LL<<60;
    for (int i = 0; i <= N; ++i) {
        // P < Q となる最大の切れ目を求める: 二分探索を終えた時の left_low
        int low = 0, high = i;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (sum[mid] >= sum[i] - sum[mid]) high = mid;
            else low = mid;
        }
        long long P = sum[low], Q = sum[i] - sum[low]; // 候補1
        long long P2 = sum[high], Q2 = sum[i] - sum[high]; // 候補2
        long long left_min = min(P, Q), left_max = max(P, Q);
        if (abs(P2-Q2) < abs(P-Q)) left_min = min(P2, Q2), left_max = max(P2, Q2);

        // R < S となる最大の切れ目を求める
        low = i, high = N;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (sum[mid] - sum[i] >= sum[N] - sum[mid]) high = mid;
            else low = mid;
        }
        long long R = sum[low] - sum[i], S = sum[N] - sum[low]; // 候補1
        long long R2 = sum[high] - sum[i], S2 = sum[N] - sum[high]; // 候補2
        long long right_min = min(R, S), right_max = max(R, S);
        if (abs(R2-S2) < abs(R-S)) right_min = min(R2, S2), right_max = max(R2, S2);

        // 真ん中の切れ目が i であるときの暫定解
        long long tmp = max(left_max, right_max) - min(left_min, right_min);
        res = min(res, tmp);
    }
    cout << res << endl;
}