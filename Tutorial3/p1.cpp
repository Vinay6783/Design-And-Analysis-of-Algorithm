#include <bits/stdc++.h>
using namespace std;

int mergeAndCount(vector<int>& arr, int l, int m, int r) 
{
    int inv = 0;
    int n1 = m - l + 1, n2 = r - m;

    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++) 
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++) 
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) 
    {
        if (left[i] <= right[j]) 
            arr[k++] = left[i++];
        else 
        {
            arr[k++] = right[j++];
            inv += (n1 - i);
        }
    }
    while(i < n1) 
        arr[k++] = left[i++];
    while(j < n2) 
        arr[k++] = right[j++];
    return inv;
}

int countInversions(vector<int>& arr, int l, int r) 
{
    int inv = 0;
    if (l < r) 
    {
        int m = (l + r) / 2;
        inv += countInversions(arr, l, m);
        inv += countInversions(arr, m + 1, r);
        inv += mergeAndCount(arr, l, m, r);
    }
    return inv;
}

int main() 
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << "Inversions: " << countInversions(arr, 0, n-1) << endl;
    return 0;
}
