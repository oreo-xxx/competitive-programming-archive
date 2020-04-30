#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

bool is_square(int n){
    int tmp = sqrt(n);
    if(tmp * tmp == n){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int n, d; cin >> n >> d;
    vector< vector<int> > x(n);
    for(int i = 0; i < n; ++i){
        vector<int> tmp(d);
        for(int j = 0; j < d; ++j){
            cin >> tmp[j];
        }
        x[i] = tmp;
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int tmp = 0;
            for(int k = 0; k < d; ++k){
                tmp += ( x[i][k] - x[j][k] ) * ( x[i][k] - x[j][k] );
            }
            if(is_square(tmp)){
                ++ans;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
