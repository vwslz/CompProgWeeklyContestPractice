#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
double det(vector<double> a) {
    double ans = 0;
    return a[0]*(a[4]*a[8] - a[5]*a[7]) + a[1]*(a[5]*a[6]-a[3]*a[8]) + a[2]*(a[3]*a[7]-a[4]*a[6]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (getline(cin, s)) {
        if (s.empty()) {
            break;
        }
        double ax,ay,bx,by,cx,cy;
        istringstream output(s);
        output >> ax >> ay >> bx >> by >> cx >> cy;
        double den = det({ax, ay, 1, bx, by, 1, cx, cy, 1});
        double e = det({ax*ax+ay*ay, ax, ay, bx*bx+by*by, bx, by, cx*cx+cy*cy, cx, cy}) / den;
        double c = -det({ax*ax+ay*ay, ay, 1, bx*bx+by*by, by, 1, cx*cx+cy*cy, cy, 1}) / den;
        double d = det({ax*ax+ay*ay, ax, 1, bx*bx+by*by, bx, 1, cx*cx+cy*cy, cx, 1}) / den;
        double h = -c/2.0;
        double k = -d/2.0;
        double r = sqrt(e+c*c/4.0+d*d/4.0);
        char signh, signk, signc, signd, signe;
        if (h > 0) {
            signh = '-';
        } else {
            signh = '+';
        }
        if (k > 0) {
            signk = '-';
        } else {
            signk = '+';
        }
        if (c > 0) {
            signc = '+';
        } else {
            signc = '-';
        }
        if (d > 0) {
            signd = '+';
        } else {
            signd = '-';
        }
        if (e > 0) {
            signe = '-';
        } else {
            signe = '+';
        }
        printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n", signh, abs(h), signk, abs(k), r);
        printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n\n", signc, abs(c), signd, abs(d), signe, abs(e));
    }
}
