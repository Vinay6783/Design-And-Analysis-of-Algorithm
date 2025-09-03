#include <bits/stdc++.h>
using namespace std;

struct Point { int x, y; };

bool cmp(Point a, Point b) 
{
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int cross(Point a, Point b, Point c) 
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<Point> buildHull(vector<Point>& pts)
{
    sort(pts.begin(), pts.end(), cmp);
    vector<Point> hull;
    for (auto p : pts) 
    {
        while (hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), p) <= 0)
            hull.pop_back();
        hull.push_back(p);
    }
    int t = hull.size();
    for (int i = pts.size()-2; i >= 0; i--) 
    {
        while (hull.size() > t && cross(hull[hull.size()-2], hull.back(), pts[i]) <= 0)
            hull.pop_back();
        hull.push_back(pts[i]);
    }
    hull.pop_back();
    return hull;
}

vector<Point> divideAndConquer(vector<Point>& pts, int l, int r) 
{
    if (l == r) 
        return {pts[l]};
    int mid = (l + r) / 2;
    auto left = divideAndConquer(pts, l, mid);
    auto right = divideAndConquer(pts, mid+1, r);
    vector<Point> combined = left;
    combined.insert(combined.end(), right.begin(), right.end());
    return buildHull(combined);
}

int main() 
{
    vector<Point> pts = {{0,0},{1,1},{2,2},{0,2},{2,0}};
    sort(pts.begin(), pts.end(), cmp);
    vector<Point> hull = divideAndConquer(pts, 0, pts.size()-1);
    for (auto p : hull) 
        cout << "(" << p.x << "," << p.y << ") ";
    return 0;
}
