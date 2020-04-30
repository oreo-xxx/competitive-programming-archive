#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
//const int MOD = 1000000007;
 const int MOD = 998244353;

// Lib
////////////////////////////
// 基本要素 (点, 線分, 円)
////////////////////////////

using DD = double;
const DD INF = 1LL<<60;      // to be set appropriately
const DD EPS = 1e-10;        // to be set appropriately
const DD PI = acos(-1.0);
DD torad(int deg) {return (DD)(deg) * PI / 180;}
DD todeg(DD ang) {return ang * 180 / PI;}

/* Point */
struct Point {
    DD x, y;
    Point(DD x = 0.0, DD y = 0.0) : x(x), y(y) {}
    friend ostream& operator << (ostream &s, const Point &p) {return s << '(' << p.x << ", " << p.y << ')';}
};
inline Point operator + (const Point &p, const Point &q) {return Point(p.x + q.x, p.y + q.y);}
inline Point operator - (const Point &p, const Point &q) {return Point(p.x - q.x, p.y - q.y);}
inline Point operator * (const Point &p, DD a) {return Point(p.x * a, p.y * a);}
inline Point operator * (DD a, const Point &p) {return Point(a * p.x, a * p.y);}
inline Point operator * (const Point &p, const Point &q) {return Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x);}
inline Point operator / (const Point &p, DD a) {return Point(p.x / a, p.y / a);}
inline Point conj(const Point &p) {return Point(p.x, -p.y);}
inline Point rot(const Point &p, DD ang) {return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y);}
inline Point rot90(const Point &p) {return Point(-p.y, p.x);}
inline DD cross(const Point &p, const Point &q) {return p.x * q.y - p.y * q.x;}
inline DD dot(const Point &p, const Point &q) {return p.x * q.x + p.y * q.y;}
inline DD norm(const Point &p) {return dot(p, p);}
inline DD abs(const Point &p) {return sqrt(dot(p, p));}
inline DD amp(const Point &p) {DD res = atan2(p.y, p.x); if (res < 0) res += PI*2; return res;}
inline bool eq(const Point &p, const Point &q) {return abs(p - q) < EPS;}
inline bool operator < (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y);}
inline bool operator > (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x > q.x : p.y > q.y);}
inline Point operator / (const Point &p, const Point &q) {return p * conj(q) / norm(q);}

/* Line */
struct Line : vector<Point> {
    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)) {
        this->push_back(a);
        this->push_back(b);
    }
    friend ostream& operator << (ostream &s, const Line &l) {return s << '{' << l[0] << ", " << l[1] << '}';}
};

/* Circle */
struct Circle : Point {
    DD r;
    Circle(Point p = Point(0.0, 0.0), DD r = 0.0) : Point(p), r(r) {}
    friend ostream& operator << (ostream &s, const Circle &c) {return s << '(' << c.x << ", " << c.y << ", " << c.r << ')';}
};


///////////////////////
// 多角形アルゴリズム
///////////////////////

// 凸包
vector<pair<Point, int> > ConvexHull(vector<pair<Point, int>> &ps) {
    int n = (int)ps.size();
    vector<pair<Point, int> > res(2*n);
    sort(ps.begin(), ps.end());
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (k >= 2) {
            while (cross(res[k-1].first - res[k-2].first, ps[i].first - res[k-2].first) < EPS) {
                --k;
                if (k < 2) break;
            }
        }
        res[k].first = ps[i].first;
        res[k].second = ps[i].second;
        ++k;
    }
    int t = k+1;
    for (int i = n-2; i >= 0; --i) {
        if (k >= t) {
            while (cross(res[k-1].first - res[k-2].first, ps[i].first - res[k-2].first) < EPS) {
                --k;
                if (k < t) break;
            }
        }
        res[k].first = ps[i].first;
        res[k].second = ps[i].second;
        ++k;
    }
    res.resize(k-1);
    return res;
}
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; cin >> N;
    
    vector<pair<Point, int>> vp(N);
    for (int i = 0; i < N; ++i){
        cin >> vp[i].first.x >> vp[i].first.y;
        vp[i].second = i;
    }

    auto ch = ConvexHull(vp);
    int n = ch.size();

    vector<DD> res(N);
    for (int i = 0; i < n; ++i) {
        Point prev = rot90(ch[(i-1+n)%n].first - ch[i].first);
        DD prevang = amp(prev);

        Point next = rot90(ch[i].first - ch[(i+1)%n].first);
        DD nextang = amp(next);

        DD ang = nextang - prevang;
        if (ang < 0){
            ang += PI * 2;
        }
        
        DD prob = ang / (PI * 2);
        
        int id = ch[i].second;
        res[id] = prob;
    }

    for (int i = 0; i < N; ++i) {
        cout << fixed << setprecision(10) << res[i] << endl;
    }
}
