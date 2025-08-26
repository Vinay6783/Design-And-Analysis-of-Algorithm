#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int l, int r) 
{
    int pivot = arr[r], i = l;
    for (int j = l; j < r; j++)
    {
        if (arr[j] <= pivot) 
            swap(arr[i++], arr[j]);
    }
    swap(arr[i], arr[r]);
    return i;
}

int kthSmallest(vector<int>& arr, int l, int r, int k) 
{
    if (k > 0 && k <= r - l + 1) 
    {
        int pos = partition(arr, l, r);
        if (pos - l == k - 1) 
            return arr[pos];
        if (pos - l > k - 1) 
            return kthSmallest(arr, l, pos - 1, k);
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
    return INT_MAX;
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << k << "-th smallest element is " << kthSmallest(arr, 0, arr.size()-1, k) << endl;
}
