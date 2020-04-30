#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

inline long long mod(long long n) {
    n %= MOD;
    if (n < 0) n += MOD;
    return n;
}

vector<long long> given;
template<class T> struct Parser {
    // results
    int root;                       // vals[root] is the answer
    vector<T> vals;                 // value of each node
    vector<char> ops;               // operator of each node ('a' means leaf values)
    vector<int> left, right;        // the index of left-node, right-node

    // member to solve each problem
    vector<int> ids; // 何番目の a か
    int id = 0;

    // generate nodes
    int newnode(char op, int lp, int rp, T val = 0) {
        ops.push_back(op); left.push_back(lp); right.push_back(rp);
        if (op == 'a') {
            vals.push_back(val);
            ids.push_back(id++);
        }
        else {
            if (op == '+') vals.push_back(mod(vals[lp] + vals[rp]));
            else if (op == '-') vals.push_back(mod(vals[lp] - vals[rp]));
            else if (op == '*') vals.push_back(mod(vals[lp] * vals[rp]));
            ids.push_back(-1);
        }
        return (int)vals.size() - 1;
    }

    // main solver
    T solve(const string &S) {
        int p = 0;
        root = expr(S, p);
        return vals[root];
    }

    // parser
    int expr(const string &S, int &p) {
        int lp = factor(S, p);
        while (p < (int)S.size() && (S[p] == '+' || S[p] == '-')) {
            char op = S[p]; ++p;
            int rp = factor(S, p);
            lp = newnode(op, lp, rp);
        }
        return lp;
    }

    int factor(const string &S, int &p) {
        int lp = value(S, p);
        while (p < (int)S.size() && (S[p]== '*' || S[p] == '/')) {
            char op = S[p]; ++p;
            int rp = value(S, p);
            lp = newnode(op, lp, rp);
        }
        return lp;
    }

    int value(const string &S, int &p) {
        if (S[p] == '(') {
            ++p;                    // skip '('
            int lp = expr(S, p);
            ++p;                    // skip ')'
            return lp;
        }
        else {
            /* each process */
            while (S[p] == 'a') ++p;
            T val = given[id];
            return newnode('a', -1, -1, val);
        }
    }
};

Parser<long long> ps;

// それぞれの a が 1 変わったらどうなるかを調べる
vector<long long> dp;
void rec(int v, long long w) {
    if (ps.ops[v] == 'a') {
        dp[ps.ids[v]] = w;
    }
    else if (ps.ops[v] == '+') {
        rec(ps.left[v], w);
        rec(ps.right[v], w);
    }
    else if (ps.ops[v] == '-') {
        rec(ps.left[v], w);
        rec(ps.right[v], mod(-w));
    }
    else if (ps.ops[v] == '*') {
        rec(ps.left[v], mod(w * ps.vals[ps.right[v]]));
        rec(ps.right[v], mod(w * ps.vals[ps.left[v]]));
    }
}

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string S; cin >> S;
    int Q; cin >> Q;
    int N = 0;
    for (int i = 0; i < S.size(); ++i) if (S[i] == 'a') ++N;
    
    given.resize(N);
    for (int i = 0; i < N; ++i) cin >> given[i];

    long long base = ps.solve(S);
    dp.resize(N);
    rec(ps.root, 1);
    for (int q = 0; q < Q; ++q) {
        long long id, x; cin >> id >> x; --id;
        long long res = mod(base + (x - given[id]) * dp[id]);
        cout << res << endl;
    }
    return 0;
}

