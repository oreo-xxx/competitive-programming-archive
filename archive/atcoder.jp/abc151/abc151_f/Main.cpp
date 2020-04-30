#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;


struct Point final {

public: ld x;
public: ld y;


public: Point subtract(const Point &p) const;

public: ld distance(const Point &p) const;

    // Signed area / determinant thing
public: ld cross(const Point &p) const;

};


struct Circle final {

public: static const Circle INVALID;

private: static const ld MULTIPLICATIVE_EPSILON;


public: Point c;   // Center
public: ld r;  // Radius


public: bool contains(const Point &p) const;

public: bool contains(const std::vector<Point> &ps) const;

};


Circle makeSmallestEnclosingCircle(const std::vector<Point> &points);
// For unit tests
Circle makeDiameter(const Point &a, const Point &b);
Circle makeCircumcircle(const Point &a, const Point &b, const Point &c);

/*---- Members of struct Point ----*/

Point Point::subtract(const Point &p) const {
    return Point{x - p.x, y - p.y};
}


ld Point::distance(const Point &p) const {
    return std::hypot(x - p.x, y - p.y);
}


ld Point::cross(const Point &p) const {
    return x * p.y - y * p.x;
}


/*---- Members of struct Circle ----*/

const Circle Circle::INVALID{Point{0, 0}, -1};

const ld Circle::MULTIPLICATIVE_EPSILON = 1 + 1e-14;


bool Circle::contains(const Point &p) const {
    return c.distance(p) <= r * MULTIPLICATIVE_EPSILON;
}


bool Circle::contains(const vector<Point> &ps) const {
    for (const Point &p : ps) {
        if (!contains(p))
            return false;
    }
    return true;
}


/*---- Smallest enclosing circle algorithm ----*/

static Circle makeSmallestEnclosingCircleOnePoint (const vector<Point> &points, size_t end, const Point &p);
static Circle makeSmallestEnclosingCircleTwoPoints(const vector<Point> &points, size_t end, const Point &p, const Point &q);

static std::default_random_engine randGen((std::random_device())());


// Initially: No boundary points known
Circle makeSmallestEnclosingCircle(const vector<Point> &points) {
    // Clone list to preserve the caller's data, randomize order
    vector<Point> shuffled = points;
    std::shuffle(shuffled.begin(), shuffled.end(), randGen);

    // Progressively add points to circle or recompute circle
    Circle c = Circle::INVALID;
    for (size_t i = 0; i < shuffled.size(); i++) {
        const Point &p = shuffled.at(i);
        if (c.r < 0 || !c.contains(p))
            c = makeSmallestEnclosingCircleOnePoint(shuffled, i + 1, p);
    }
    return c;
}


// One boundary point known
static Circle makeSmallestEnclosingCircleOnePoint(const vector<Point> &points, size_t end, const Point &p) {
    Circle c{p, 0};
    for (size_t i = 0; i < end; i++) {
        const Point &q = points.at(i);
        if (!c.contains(q)) {
            if (c.r == 0)
                c = makeDiameter(p, q);
            else
                c = makeSmallestEnclosingCircleTwoPoints(points, i + 1, p, q);
        }
    }
    return c;
}


// Two boundary points known
static Circle makeSmallestEnclosingCircleTwoPoints(const vector<Point> &points, size_t end, const Point &p, const Point &q) {
    Circle circ = makeDiameter(p, q);
    Circle left  = Circle::INVALID;
    Circle right = Circle::INVALID;

    // For each point not in the two-point circle
    Point pq = q.subtract(p);
    for (size_t i = 0; i < end; i++) {
        const Point &r = points.at(i);
        if (circ.contains(r))
            continue;

        // Form a circumcircle and classify it on left or right side
        ld cross = pq.cross(r.subtract(p));
        Circle c = makeCircumcircle(p, q, r);
        if (c.r < 0)
            continue;
        else if (cross > 0 && (left.r < 0 || pq.cross(c.c.subtract(p)) > pq.cross(left.c.subtract(p))))
            left = c;
        else if (cross < 0 && (right.r < 0 || pq.cross(c.c.subtract(p)) < pq.cross(right.c.subtract(p))))
            right = c;
    }

    // Select which circle to return
    if (left.r < 0 && right.r < 0)
        return circ;
    else if (left.r < 0)
        return right;
    else if (right.r < 0)
        return left;
    else
        return left.r <= right.r ? left : right;
}


Circle makeDiameter(const Point &a, const Point &b) {
    Point c{(a.x + b.x) / 2, (a.y + b.y) / 2};
    return Circle{c, max(c.distance(a), c.distance(b))};
}


Circle makeCircumcircle(const Point &a, const Point &b, const Point &c) {
    // Mathematical algorithm from Wikipedia: Circumscribed circle
    ld ox = (min(min(a.x, b.x), c.x) + max(min(a.x, b.x), c.x)) / 2;
    ld oy = (min(min(a.y, b.y), c.y) + max(min(a.y, b.y), c.y)) / 2;
    ld ax = a.x - ox,  ay = a.y - oy;
    ld bx = b.x - ox,  by = b.y - oy;
    ld cx = c.x - ox,  cy = c.y - oy;
    ld d = (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) * 2;
    if (d == 0)
        return Circle::INVALID;
    ld x = ((ax*ax + ay*ay) * (by - cy) + (bx*bx + by*by) * (cy - ay) + (cx*cx + cy*cy) * (ay - by)) / d;
    ld y = ((ax*ax + ay*ay) * (cx - bx) + (bx*bx + by*by) * (ax - cx) + (cx*cx + cy*cy) * (bx - ax)) / d;
    Point p{ox + x, oy + y};
    ld r = max(max(p.distance(a), p.distance(b)), p.distance(c));
    return Circle{p, r};
}

void solve() {
    ll n; cin >> n;
    vector<Point> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].x >> vec[i].y;
    }
    auto c = makeSmallestEnclosingCircle(vec);
    ld ans = c.r;
    cout << fixed << setprecision(10) << ans << endl;
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
