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

const int CASES = 3;

void solve() {
    string s; cin >> s;
    int n = s.size();
    deque<char> dq;
    for (int i = 0; i < n; ++i) {
        dq.push_back(s[i]);
    }
    int Q; cin >> Q;
    int num = 0;
    for (int _ = 0; _ < Q; ++_) {
        int t; cin >> t;
        if(t==1){
            ++num;
        }
        else{
            int f; char c;
            cin >> f >> c;
            if(f==1){
                if(num % 2 != 0){
//                    s += c;
                    dq.push_back(c);
                }
                else{
//                    s.insert(0, 1, c);
                    dq.push_front(c);
                }
            }
            else{
                if(num % 2 == 0){
//                    s += c;
                    dq.push_back(c);
                }
                else{
//                    s.insert(0, 1, c);
                    dq.push_front(c);
                }
            }
        }
    }
    if(num % 2 != 0) reverse(dq.begin(), dq.end());
    int m = dq.size();
    for (int i = 0; i < m; ++i) {
        cout << dq[i];
        if(i == m-1) cout << endl;
    }
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
