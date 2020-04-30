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
    string X; cin >> X;
    int stack = 0, count = 0;
    for (int i = 0; i < X.size(); ++i) {
        if (X[i] == 'S'){
            ++stack;
        }
        else if(X[i] == 'T' && stack > 0){
            --stack;
            ++count;
        }
    }
    int ans = X.size() - count*2;
    cout << ans << endl;
    return 0;
}
