#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library
//

bool comp(const int lh, const int rh) {
    int tmp_l = lh % 10;
    int tmp_r = rh % 10;
    return (lh % 10) > (rh % 10);
}

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int ans = 0;
    vector<int> vec;
    for(int i = 0; i < 5; ++i){
        int tmp; cin >> tmp;
        if(tmp % 10 == 0){
            ans += tmp;
        }
        else{
            vec.push_back(tmp);
        }
    }
    sort(vec.begin(), vec.end(), comp);
    if(vec.empty()){
        cout << ans << endl;
        return 0;
    }
    
    for(int i = 0; i < vec.size() - 1; ++i) {
        int tmp = vec[i] / 10;
        ans += (tmp + 1) * 10;
    }
    ans += vec[vec.size() - 1];

    cout << ans << endl;
    return 0;
}
