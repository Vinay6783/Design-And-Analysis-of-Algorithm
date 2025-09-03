#include<bits/stdc++.h>
using namespace std;

void dualPivotPartition(vector<int>& a, int low, int high, int &lp, int &rp) 
{
    if (a[low] > a[high])
        swap(a[low], a[high]);
    int p = a[low], q = a[high];
    int lt = low + 1, gt = high - 1, i = lt;
    while (i <= gt) 
    {
        if (a[i] < p) 
            swap(a[i++], a[lt++]);
        else if (a[i] > q) 
            swap(a[i], a[gt--]);
        else 
            i++;
    }
    lt--; 
    gt++;
    swap(a[low], a[lt]);
    swap(a[high], a[gt]);
    lp = lt; 
    rp = gt;
}
void dualPivotQuickSort(vector<int>& a, int low, int high)
{
    if (low >= high) return;
    int lp, rp;
    dualPivotPartition(a, low, high, lp, rp);
    dualPivotQuickSort(a, low, lp-1);
    dualPivotQuickSort(a, lp+1, rp-1);
    dualPivotQuickSort(a, rp+1, high);
}

int main()
{
    vector<int> arr = {4, 7, 2, 9, 1, 5};
    dualPivotQuickSort(arr, 0, arr.size() - 1);
    for (int x : arr) 
        cout << x << " ";
    return 0;
}
