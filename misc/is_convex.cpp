#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 1e-9
#define PI acos(-1.0)

double DEG_to_RAD(double d){return d * PI / 180.0;}
double RAD_to_DEG(double r){return r * 180.0 / PI;}

struct point
{
    double x, y;
    point() {x = y = 0.0;}
    point(double _x, double _y): x(_x), y(_y) {}
    bool operator == (point other) const
    {
        return (fabs(x-other.x) < EPS && (fabs(y-other.y) < EPS));
    }
};

struct vec
{
    double x, y;
    vec (double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b)
{
    return vec(b.x - a.x, b.y - a.y);
}

double dist(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double perimeter(const vector<point> &P)
{
    double result = 0.0;
    for (int i=0; i < (int)P.size()-1; ++i)
        result += dist(P[i], P[i+1]);
    return result;
}

double area(const vector<point> &P)
{
    double result = 0.0, x1, y1, x2, y2;
    for (int i=0; i < (int)P.size()-1; ++i)
    {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}

double dot(vec a, vec b) {return a.x * b.x + a.y * b.y;}
double cross(vec a, vec b) {return a.x * b.y - a.y * b.x;}
double norm_sq(vec v) {return v.x * v.x + v.y * v.y;}
double angle(point a, point o, point b)
{
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa)*norm_sq(ob)));
}

double ccw(point p, point q, point r)
{
    return cross(toVec(p, q), toVec(p,r)) > 0;
}

bool is_convex(const vector<point> &P)
{
    int sz = (int)P.size();
    if (sz <= 3) return false;
    bool is_left = ccw(P[0], P[1], P[2]);
    for (int i=1; i < sz-1; ++i)
    {
        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != is_left)
            return false;
    }
    return true;
}

int main()
{
    vector<point> P;
    P.push_back(point(1,1));
    P.push_back(point(3,3));
    P.push_back(point(9,1));
    P.push_back(point(12,4));
    P.push_back(point(9,7));
    P.push_back(point(1,7));
    P.push_back(P[0]); //important: loop back

    printf("perimeter of polygon: %.2lf\n", perimeter(P));
    printf("area of polygon: %.2lf\n", area(P));
    printf("is convex: %d \n", is_convex(P));

    return 0;
}




