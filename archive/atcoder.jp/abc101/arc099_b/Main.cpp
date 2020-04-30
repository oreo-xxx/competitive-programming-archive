#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = pair<int, ll>;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

long long f(long long n) {
  long long res = 0;
  while (n > 0) {
    res += n%10;
    n /= 10;
  }
  return res;
}

double g(long long n) {
  return (double)(n)/f(n);
}

int main() {
  vector<long long> res;
  long long base = 1;

  // まずは候補を (1〜150)99999 的なやつを全列挙
  for (int i = 0; i < 15; ++i) {
    for (int j = 1; j < 150; ++j) {
      res.push_back(base * (j+1) - 1);
    }
    base *= 10;
  }
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());

  // ダメなやつを除く: O(n^2) かかる効率悪い実装だけどとりあえず
  for (long long i = 0; i < res.size(); ++i) {
    for (long long j = i+1; j < res.size(); ++j) {
      if (g(res[i]) > g(res[j])) {
        res.erase(res.begin() + i--);
        break;
      }
    }
  }

  long long K;
  cin >> K;
  for (long long i = 0; i < K; ++i) {
    cout << res[i] << endl;
  }
}
