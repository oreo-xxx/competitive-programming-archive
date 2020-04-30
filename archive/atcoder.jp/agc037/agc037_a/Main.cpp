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
    string S; cin >> S;
    int N = S.size();
    set<string> st;
    int ans = 0;
    int tmp = 1;

    for(int left = 0; left < N;){
        int width_l = tmp;
        int width_r = 1;
        while(true){
            string l = S.substr(left, width_l);
            string r = S.substr(left + width_l, width_r);
            if(l != r) {
                left += width_l;
                tmp = width_r;
                ++ans;
                break;
            }
            else{
                if(left + width_l + width_r >= N){
                    ++ans;
                    left = N;
                    break;
                }
                ++width_r;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
