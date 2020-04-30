#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//
int N;
ll ans = 0;
vector<ll> A;
vector<ll> B;

int check(int l, int c, int r){
    if(B[c] - B[l] - B[r] >= A[c]){
        return true;
    }
    return false;
}

void proc(int l, int c, int r){
    ll tmp = (B[c]-A[c]) / (B[l] + B[r]);
    B[c] -= tmp * (B[l] + B[r]);
    ans += tmp;
    return;
}

void bfs(){
    queue<int> que;
    if(check(N-1, 0, 1)){
        que.push(0);
    }
    if(check(N-2,N-1, 0)){
        que.push(N-1);
    }

    for(int i = 1; i < N - 1; ++i){
        if(check(i-1, i, i + 1)){
            que.push(i);
        }
    }

    while (!que.empty()) {
        int idx = que.front(); que.pop();
        int l, r;
        if(idx == 0){l = N-1; r = 1;}
        else if(idx == N - 1){l = N-2; r = 0;}
        else{l = idx-1; r = idx + 1;}

        proc(l, idx, r);

        int l_l, l_r;
        if(l == 0){l_l = N-1; l_r = 1;}
        else if(l == N - 1){l_l = N-2; l_r = 0;}
        else{l_l = l-1; l_r = l + 1;}
        if (check(l_l, l, l_r)) {
            que.push(l);
        }

        int r_l, r_r;
        if(r == 0){r_l = N-1; r_r = 1;}
        else if(r == N - 1){r_l = N-2; r_r = 0;}
        else{r_l = r-1; r_r = r + 1;}
        if (check(r_l, r, r_r)) {
            que.push(r);
        }
    }
    return;
}

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> N;
    A.resize(N);
    B.resize(N);
    for(int i = 0; i < N; ++i){cin >> A[i];}
    for(int i = 0; i < N; ++i){cin >> B[i];}

    bfs();

    for(int i = 0; i < N; ++i){
        if(B[i] != A[i]){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
    return 0;
}
