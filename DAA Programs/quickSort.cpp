#include <iostream>
using namespace std;
int swapCount = 0, conditionCount = 0;
int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        conditionCount++;
        if (arr[j] <= x)
        {
            swapCount++;
            i += 1;
            swap(arr[i], arr[j]);
        }
    }
    swapCount++;
    swap(arr[i + 1], arr[r]);
    return i + 1;
}
void quickSort(int arr[], int p, int r)
{
    if (p >= r)
    {
        return;
    }
    else
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}
int main()
{
    int arr[10000];
    freopen("testCases.txt", "r", stdin);
    freopen("quickResult.txt", "w", stdout);
    int t = 1000;
    int n = 1;
    while (t--)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        quickSort(arr, 0, n - 1);
        cout << n << ")swap count : " << swapCount << ", And comparison : " << conditionCount << "\n";

        n++;
        swapCount = 0;
        conditionCount = 0;
    }
    return 0;
}