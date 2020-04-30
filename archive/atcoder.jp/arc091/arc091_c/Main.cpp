#include <iostream>
#include <vector>
using namespace std;


vector<long long> LISLDS(long long N, long long A, long long B) {
    vector<long long> res;
    for (long long i = B-1; i >= 0; --i) res.push_back(i);
    if (A == 1) return res;
    long long rem = N - B;
    long long p = rem / (A-1);
    long long r = rem % (A-1);
    long long b = r;
    long long c = A-1-r;
    for (int i = 0; i < b; ++i) {
        int size = (int)res.size();
        for (int j = 0; j < p+1; ++j) {
            res.push_back(size + p - j);
        }
    }
    for (int i = 0; i < c; ++i) {
        int size = (int)res.size();
        for (int j = 0; j < p; ++j) {
            res.push_back(size + p-1 - j);
        }
    }
    return res;
}


int main() {
    long long N, A, B; cin >> N >> A >> B;
    if (A + B > N+1 || A * B < N) cout << -1 << endl;
    else {
        vector<long long> res = LISLDS(N, A, B);
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] + 1;
            if (i != (int)res.size() - 1) cout << " ";
        }
        cout << endl;
    }
}
