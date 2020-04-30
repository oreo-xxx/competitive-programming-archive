#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N, X; cin >> N >> X;
    vector<int> L(N);
    for(int i = 0; i < N; ++i){
        cin >> L[i];
    }
    vector<int> hane(N + 1);
    for(int i = 0; i < N; ++i){
        hane[i+1] = hane[i] + L[i];
    }

    int ans = 0;
    for(int i = 0; i < N + 1; ++i){
        if(hane[i] > X){
            break;
        }
        ++ans;
    }

    cout << ans << endl;
    return 0;
}
