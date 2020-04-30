#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 4;

ll n;
vector<char> buf;
void rec(int idx, int num){
    if(idx == n){
        for(int i = 0; i < n; ++i){
            cout << buf[i];
        }
        cout << endl;
    }
    else{
        for(int i = 0; i <= num; ++i){
            char c = i + 'a';
            buf[idx] = c;
            bool f = true;
            int cnt = num;
            if(i==num)++cnt;
            rec(idx+1, cnt);
        }
    }
}

void solve() {
    cin >> n;
    buf.resize(n);
    rec(0, 0);
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
#else

    solve();

#endif
    return 0;
}
