#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

using Data = pair<long long, vector<int> >;

int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int a, b, c, K;
    cin >> a >> b >> c >> K;
    vector<ll> A(a);
    vector<ll> B(b);
    vector<ll> C(c);
    for (int i = 0; i < a; ++i) cin >> A[i];
    sort(A.begin(), A.end(), greater<ll>());

    for (int i = 0; i < b; ++i) cin >> B[i];
    sort(B.begin(), B.end(), greater<ll>());

    for (int i = 0; i < c; ++i) cin >> C[i];
    sort(C.begin(), C.end(), greater<ll>());

    priority_queue<Data> que;
    set<Data> se;
    que.push(Data(A[0] + B[0] + C[0], vector<int>({0, 0, 0})));
    for (int k = 0; k < K; ++k) {
        auto top = que.top();que.pop();
        cout << top.first << endl;

        if(top.second[0] + 1 < a){
            long long sum = top.first - A[top.second[0]] + A[top.second[0] + 1];
            auto num = top.second;
            num[0]++;
            auto d = Data(sum, num);
            if (!se.count(d)){
                se.insert(d), que.push(d);
            }
        }

        if(top.second[1] + 1 < b){
            long long sum = top.first - B[top.second[1]] + B[top.second[1] + 1];
            auto num = top.second;
            num[1]++;
            auto d = Data(sum, num);
            if (!se.count(d)){
                se.insert(d), que.push(d);
            }
        }

        if(top.second[2] + 1 < c){
            long long sum = top.first - C[top.second[2]] + C[top.second[2] + 1];
            auto num = top.second;
            num[2]++;
            auto d = Data(sum, num);
            if (!se.count(d)){
                se.insert(d), que.push(d);
            }
        }
    }
    return 0;
}
