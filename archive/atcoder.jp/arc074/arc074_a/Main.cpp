#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, uint>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

void solve(){
    ll H, W; cin >> H >> W;
    ll a=0,b=0,c=0;

    ll ans = INF64;
    for(int h = 0; h <= H; h++){
        if(W % 2==0){
            a = h*W/2;
            b = h*W/2;
        }
        else{
            a = h*(W-1)/2;
            b = h*(W+1)/2;
        }
        c = W*(H-h);

        ll s_max = max(max(a,b),c);
        ll s_min = min(min(a,b),c);
        ans = min(ans, s_max - s_min);

        a = h*W;
        if((H-h)%2==0){
            b = (H-h)/2 * W;
            c = b;
        }
        else{
            b = (H-h-1)/2 * W;
            c = (H-h+1)/2 * W;
        }

        s_max = max(max(a,b),c);
        s_min = min(min(a,b),c);
        ans = min(ans, s_max - s_min);
    }

    for(int w = 0; w <= W; w++){
        if(H%2==0){
            a = H/2*w;
            b = a;
        }
        else{
            a = (H-1)/2*w;
            b = (H+1)/2*w;
        }
        c = H*(W-w);

        ll s_max = max(max(a,b),c);
        ll s_min = min(min(a,b),c);
        ans = min(ans, s_max - s_min);

        a = w*H;
        if((W-w)%2==0){
            b = H*(W-w)/2;
            c = b;
        }
        else{
            b = H*(W-w-1)/2;
            c = H*(W-w+1)/2;
        }
        s_max = max(max(a,b),c);
        s_min = min(min(a,b),c);
        ans = min(ans, s_max - s_min);
    }

    cout << ans << endl;

    return;
}



int main() {
    #ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt"};
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

