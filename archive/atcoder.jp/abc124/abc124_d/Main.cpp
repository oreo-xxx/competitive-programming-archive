#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//
void add(ll &a, ll b){
    a += b;
    if (a >= MOD) a -= MOD;
}

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N, K; cin >> N >> K;
    string S; cin >> S;

    // 「1 の個数」「0 の個数」を交互に記録していく
    vector<int> nums;
    if (S[0] == '0') nums.push_back(0); // 先頭が 0 だったら
    for (int i = 0; i < S.size();) {
        int j = i;
        while (j < S.size() && S[j] == S[i]) ++j; // S[i] の数値がどこまで続くか
        nums.push_back(j - i);
        i = j;
    }
    if (S.back() == '0') nums.push_back(0); // 最後尾が 0 だったら

    // 累積和
    vector<int> sums(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); ++i) sums[i+1] = sums[i] + nums[i];

    // 偶数番目の添字から始まる、長さ 2K+1 (以下) の区間の総和のうち、最大値を求める
    int res = 0;
    for (int left = 0; left < sums.size(); left += 2) {
        int right = left + K*2+1;
        if (right >= sums.size()) right = (int)sums.size() - 1;
        res = max(res, sums[right] - sums[left]);
    }
    cout << res << endl;
}
