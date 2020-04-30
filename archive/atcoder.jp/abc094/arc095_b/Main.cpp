#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int left = a[n-1];
    a.pop_back();

    int half= left/2;
    if(left%2==1){half=(1+left)/2;}
    int right = 0;
    int dist=INF32;
    for(int i = 0; i < n; ++i){
          int tmp = abs(half-a[i]);
          if(dist>tmp){
               dist=tmp;
               right=a[i];
          } 
    }

    cout << left << " " << right << endl;

    return ;
}

int main() {
    #ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
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

