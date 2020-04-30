#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//

int N;
vector<double> x, y;
vector<char> d;

double area(double t) {
    double xmi = INF, xma = -INF, ymi = INF, yma = -INF;
    for (int i = 0; i < N; ++i) {
        double cx, cy;
        if (d[i] == 'L') cx = x[i] - t, cy = y[i];
        else if (d[i] == 'R') cx = x[i] + t, cy = y[i];
        else if (d[i] == 'U') cx = x[i], cy = y[i] + t;
        else cx = x[i], cy = y[i] - t;
        xmi = min(xmi, cx);
        xma = max(xma, cx);
        ymi = min(ymi, cy);
        yma = max(yma, cy);
    }
    return (xma - xmi) * (yma - ymi);
}

double solve() {
    vector<double> alt;
    alt.push_back(0);

    // 左
    {
        double mi1 = INF; // L
        double mi2 = INF; // R
        double mi3 = INF; // UD
        for (int i = 0; i < N; ++i) {
            if (d[i] == 'L') {
                mi1 = min(mi1, x[i]);
            }
            else if (d[i] == 'R') {
                mi2 = min(mi2, x[i]);
            }
            else {
                mi3 = min(mi3, x[i]);
            }
        }
        if (mi1 < INF && mi2 < INF) alt.push_back( abs(mi1 - mi2) / 2 );
        if (mi1 < INF && mi3 < INF) alt.push_back( abs(mi1 - mi3) );
        if (mi2 < INF && mi3 < INF) alt.push_back( abs(mi2 - mi3) );
    }

    // 右
    {
        double ma1 = -INF; // L
        double ma2 = -INF; // R
        double ma3 = -INF; // UD
        for (int i = 0; i < N; ++i) {
            if (d[i] == 'L'){
                ma1 = max(ma1, x[i]);
            }
            else if (d[i] == 'R') {
                ma2 = max(ma2, x[i]);
            }
            else {
                ma3 = max(ma3, x[i]);
            }
        }
        if (ma1 > -INF && ma2 > -INF) alt.push_back( abs(ma1 - ma2) / 2 );
        if (ma1 > -INF && ma3 > -INF) alt.push_back( abs(ma1 - ma3) );
        if (ma2 > -INF && ma3 > -INF) alt.push_back( abs(ma2 - ma3) );
    }

    // 下
    {
        double mi1 = INF; // D
        double mi2 = INF; // U
        double mi3 = INF; //
        for (int i = 0; i < N; ++i) {
            if (d[i] == 'D') mi1 = min(mi1, y[i]);
            else if (d[i] == 'U') mi2 = min(mi2, y[i]);
            else mi3 = min(mi3, y[i]);
        }
        if (mi1 < INF && mi2 < INF) alt.push_back( abs(mi1 - mi2) / 2 );
        if (mi1 < INF && mi3 < INF) alt.push_back( abs(mi1 - mi3) );
        if (mi2 < INF && mi3 < INF) alt.push_back( abs(mi2 - mi3) );
    }

    // 上
    {
        double ma1 = -INF; // U
        double ma2 = -INF; // D
        double ma3 = -INF; //
        for (int i = 0; i < N; ++i) {
            if (d[i] == 'D') ma1 = max(ma1, y[i]);
            else if (d[i] == 'U') ma2 = max(ma2, y[i]);
            else ma3 = max(ma3, y[i]);
        }
        if (ma1 > -INF && ma2 > -INF) alt.push_back( abs(ma1 - ma2) / 2 );
        if (ma1 > -INF && ma3 > -INF) alt.push_back( abs(ma1 - ma3) );
        if (ma2 > -INF && ma3 > -INF) alt.push_back( abs(ma2 - ma3) );
    }

    sort(alt.begin(), alt.end());
    alt.erase(unique(alt.begin(), alt.end()), alt.end());
    double res = INF;
    for (int i = 0; i < alt.size(); ++i) {
        double tmp = area(alt[i]);
        res = min(res, tmp);
    }

    return res;
}


int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> N;
    x.resize(N), y.resize(N), d.resize(N);
    for (int i = 0; i < N; ++i){
        cin >> x[i] >> y[i] >> d[i];
    }
    double res = solve();
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}
