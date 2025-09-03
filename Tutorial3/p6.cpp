#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeSkyline(vector<vector<int>>& A, vector<vector<int>>& B) 
{
    vector<vector<int>> res;
    int i = 0, j = 0, h1 = 0, h2 = 0;
    while (i < A.size() || j < B.size()) 
    {
        int x;
        if (j == B.size() || (i < A.size() && A[i][0] < B[j][0])) 
        {
            x = A[i][0]; 
            h1 = A[i][1]; 
            i++;
        } 
        else if (i == A.size() || B[j][0] < A[i][0]) 
        {
            x = B[j][0]; 
            h2 = B[j][1]; 
            j++;
        } 
        else 
        {
            x = A[i][0]; 
            h1 = A[i][1]; 
            h2 = B[j][1]; 
            i++; 
            j++;
        }
        int h = max(h1, h2);
        if (res.empty() || res.back()[1] != h) 
            res.push_back({x, h});
    }
    return res;
}

vector<vector<int>> solve(vector<vector<int>>& b, int l, int r) 
{
    if (l == r) 
        return {{b[l][0], b[l][2]}, {b[l][1], 0}};
    int m = (l + r) / 2;
    auto L = solve(b, l, m), R = solve(b, m+1, r);
    return mergeSkyline(L, R);
}

vector<vector<int>> getSkyline(vector<vector<int>>& b) 
{
    if (b.empty()) return {};
    return solve(b, 0, b.size()-1);
}

int main() 
{
    vector<vector<int>> b = {
        {1,5,11},{2,7,6},{3,9,13},{12,16,7},
        {14,25,3},{19,22,18},{23,29,13},{24,28,4}
    };
    auto sky = getSkyline(b);
    for (auto &p : sky) 
        cout << "[" << p[0] << "," << p[1] << "] ";
    return 0;
}
