#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int MOD = 1000000007;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n, k; cin >> n >> k;

    int ans = 0;
    if(k == 1){
        ans = 0;
    }
    else{
        ans = n - k;
    }
    cout <<  ans << endl;
    return 0;
}

