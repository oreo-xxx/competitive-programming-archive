#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library

//
int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int xmax = INF32 * -1;
    int ymin = INF32;
    for(int i = 0; i < n; ++i){
        int tmp; cin >> tmp;
        xmax = max(xmax, tmp);
    }
    for(int i = 0; i < m; ++i){
        int tmp; cin >> tmp;
        ymin = min(ymin, tmp);
    }
    bool flag = false;
    for(int i = x + 1; i <= y; ++i){
        if(xmax < i && i <= ymin){
            flag = true;
            break;
        }
    }

    if(flag){
        cout << "No War" << endl;
    }
    else{
        cout << "War" << endl;
    }
    return 0;
}

