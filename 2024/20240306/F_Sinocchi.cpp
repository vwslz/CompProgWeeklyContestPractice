#include <bits/stdc++.h>
using namespace std;
#define pb push_back

#define int long long
const double EPS = 1E-9;

struct pt {
    double x, y;
    pt(){};
    pt(int X, int Y){x=X;y=Y;}
    bool operator<(const pt& p) const
    {
        return x < p.x - EPS || (abs(x - p.x) < EPS && y < p.y - EPS);
    }
};

struct line {
    double a, b, c;

    line() {}
    line(pt p, pt q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }

    void norm()
    {
        double z = sqrt(a * a + b * b);
        if (abs(z) > EPS)
            a /= z, b /= z, c /= z;
    }

    double dist(pt p) const { return a * p.x + b * p.y + c; }
};

double det(double a, double b, double c, double d)
{
    return a * d - b * c;
}

inline bool betw(double l, double r, double x)
{
    return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}

inline bool intersect_1d(double a, double b, double c, double d)
{
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d) + EPS;
}

bool intersect(pt a, pt b, pt c, pt d, pt& left, pt& right)
{
    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
        return false;
    line m(a, b);
    line n(c, d);
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS) {
        if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS)
            return false;
        if (b < a)
            swap(a, b);
        if (d < c)
            swap(c, d);
        left = max(a, c);
        right = min(b, d);
        return true;
    } else {
        left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
        left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
        return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
               betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
    }
}
double area(pt p1, pt p2, pt p3){
    double A = abs((p2.x - p1.x)*(p3.y - p2.y) - (p3.x-p2.x)*(p2.y - p1.y));

    return A;
}
void solve(){
    int n; cin >> n;

    vector<pt> v;
    for (int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        v.pb(pt(x, y));
    }
    pt FAR = pt(20193, 26049);
    pt f1 = pt();
    pt f2 = pt();
    int q; cin >> q;
    for (int i=0; i<q; i++){
        int x, y; cin >> x >> y;
        pt cur = pt(x, y);
        int nintr = 0;
        int found = 0;
        for (int i=0; i<n; i++){
            nintr += intersect(v[i], v[(i+1)%n], cur, FAR, f1, f2);
            if (area(v[i], v[(i+1)%n], cur) < EPS &&
            betw(v[i].x, v[(i+1)%n].x, cur.x) &&
            betw(v[i].y, v[(i+1)%n].y, cur.y)) found = 1;
        }
        if (found || nintr%2){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }


}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    // inv_init();
    int t; t=1;
    cin >> t;
    for (int i=0; i<t; i++){
        cout << "Case " << i+1 << ": " << "\n";
        solve();
    }
}      // list<int> L = {1, 2, 3, 4};
