#include <iostream>
#include <climits>
using namespace std;
int swapCount = 0, conditionCount = 0;
void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
        swapCount++;
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[q + i + 1];
        swapCount++;
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0, j = 0;
    for (int k = p; k <= r; k++)
    {
        conditionCount++;
        if (L[i] <= R[j])
        {
            swapCount++;
            arr[k] = L[i];
            i += 1;
        }
        else
        {
            swapCount++;
            arr[k] = R[j];
            j += 1;
        }
    }
    return;
}
void mergeSort(int arr[], int p, int r)
{
    if (p >= r)
        return;
    else
    {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}
int main()
{
    int arr[10000];
    freopen("testCases.txt", "r", stdin);
    freopen("mergeResult.txt", "w", stdout);
    int t = 1000;
    int n = 1;
    while (t--)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        mergeSort(arr, 0, n - 1);
        cout << n << ")swap count : " << swapCount << ", And comparison : " << conditionCount << "\n";
        n++;
        conditionCount = 0;
        swapCount = 0;
    }
}