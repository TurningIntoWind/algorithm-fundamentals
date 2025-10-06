#include <iostream>

using namespace std;

const int N = 1e5 + 9;
int a[N], temp[N];

void merge_sort(int l, int r)
{
	if (l >= r)
		return;

	int mid = l + r >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);

	int i, j, k;
	for (i = l; i <= r; i++)
		temp[i] = a[i];

	i = k = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (temp[i] <= temp[j])
			a[k++] = temp[i++];
		else
			a[k++] = temp[j++];
	}
	while (i <= mid)
		a[k++] = temp[i++];
	while (j <= r)
		a[k++] = temp[j++];
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);

	merge_sort(0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	return 0;
}