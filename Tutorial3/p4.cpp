#include <bits/stdc++.h>
using namespace std;

int findPeak(vector<int> &A, int left, int right, int n) 
{
    int mid = (left + right) / 2;
    if ((mid == 0 || A[mid] >= A[mid - 1]) && (mid == n - 1 || A[mid] >= A[mid + 1])) 
        return mid;

    if (mid > 0 && A[mid - 1] > A[mid])
        return findPeak(A, left, mid - 1, n);

    return findPeak(A, mid + 1, right, n);
}

int main() 
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) 
        cin >> A[i];
    int peakIndex = findPeak(A,0,n-1,n);
    cout << "Peak found at index: " << peakIndex << " with value: " << A[peakIndex] << endl;
    return 0;
}
