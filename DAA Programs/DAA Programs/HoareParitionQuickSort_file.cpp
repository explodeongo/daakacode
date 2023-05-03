#include <iostream>
using namespace std;
int swapCount=0,conditionCount=0;
int HoarePartition(int A[], int p, int r)
{
	int x = A[p];
	int i = p - 1;
	int j = r + 1;
	while (true)
	{
		do
		{
			i++;
			conditionCount++;
		} while (A[i] < x);

		do
		{
			j--;
			conditionCount++;
		} while (A[j] > x);
		conditionCount++;
		if (i >= j)
			return j;
		swap(A[i], A[j]);
		swapCount++;
	}
}

void QuickSort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = HoarePartition(A, p, r);
		QuickSort(A, p, q);
		QuickSort(A, q + 1, r);
	}
}
int main()
{
	int A[1000];
	freopen("testCases.txt", "r", stdin);
	freopen("swapHoareResult.txt", "w", stdout);
	int t = 1000;
	int n = 1;
	while (t--)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		QuickSort(A, 0, n - 1);
		cout<<n<<")swap count : "<<swapCount<<", And comparison : "<<conditionCount<<"\n";
		n++;
		swapCount=0;
		conditionCount=0;
	}
}