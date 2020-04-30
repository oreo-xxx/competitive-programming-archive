#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};


int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n; cin >> n;
    vector<int> p(n);
    vector<int> p2(n);
    for(int i = 0;i < n; i++){
        cin >> p[i];
        p2[i] = p[i];
    }

    int count1 = 0;
    if(p[0] == 1){
        swap(p[0], p[1]);
        ++count1;
    }

    for(int i = 1;i < n; i++){
        if(p[i] == i + 1){
            swap(p[i], p[i + 1]);
            ++count1;
        }
    }

    int count2 = 0;
    if(p2[n - 1] == n){
        swap(p2[n - 1], p2[n - 2]);
        ++count2;
    }

    for(int i = n - 2;i >= 0; --i){
        if(p2[i] == i + 1){
            swap(p2[i], p2[i + 1]);
            ++count2;
        }
    }

    int ans = min(count1, count2);

    cout << ans << endl;

    return 0;
}

