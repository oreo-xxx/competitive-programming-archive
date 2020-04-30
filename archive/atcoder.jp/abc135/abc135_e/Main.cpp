#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

/// Lib
///

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int K, X, Y;
    cin >> K >> X >> Y;

    // 1手でいける場合を先に処理
    if(abs(X) + abs(Y) == K){
        cout << "1" << endl;
        cout << X << " " << Y << endl;
        return 0;
    }

    // X >= Y >= 0に変換
    int xsign = 1, ysign = 1;
    bool sw = false;
    if(X < 0){
        X *= -1;
        xsign = -1;
    }
    if(Y < 0){
        Y *= -1;
        ysign = -1;
    }
    if(X < Y){
        swap(X, Y);
        sw = true;
    }

    // nがステップ数。1手で行けないので最小でも2
    int D = X + Y;
    int n = max(2, (D + K - 1)/K);

    // 無駄分が奇数の場合、Kが奇数なら1ステップ増やして偶数に。Kが偶数なら無理
    if((n * K - D) % 2 != 0){
        if(K % 2 != 0){
            n++;
        }
        else{
            cout << -1 << endl;
            return 0;
        }
    }

    vector<P> ans;

    // 構築。n=3のときだけ特別
    int R = (n * K - D)/2;
    if(n == 3){
        int b = R / 2;
        int a = R - b;
        for(int i = 1; i <= n; i++){
            int l = i * K;
            if(l <= a){
                ans.emplace_back(-l, 0);
            }
            else if(l <= a + Y + b){
                l -= a;
                ans.emplace_back(-a, l);
            }
            else if(l <= a + Y + b + a + X){
                l -= a+Y+b;
                ans.emplace_back(l-a, b+Y);
            }
            else{
                l -= a + Y + b + a + X;
                ans.emplace_back(X, Y + (b-l));
            }
        }
    }
    else{
        int a = R;
        for(int i = 1; i <= n; ++i){
            int l = i * K;
            if(l <= Y + a){
                ans.emplace_back(0, l);
            }
            else if(l <= Y + a + X){
                l -= Y + a;
                ans.emplace_back(l, Y + a);
            }
            else{
                l -= Y + a + X;
                ans.emplace_back(X, Y + (a - l));
            }
        }
    }

    // 座標変換を戻して出力
    if(sw){
        for(int i = 0; i < n; ++i){
            swap(ans[i].first, ans[i].second);
        }
    }
    cout << n << endl;
    for(auto& p : ans){
        cout << p.first * xsign << " " << p.second * ysign << endl;
    }

    return 0;
}
