#include<iostream>
#include<string>
#include<cassert>
using namespace std;


int* generateRandomArray(int n, int rangeL, int rangeR) {
	assert(rangeL <= rangeR);

	int* arr = new int[n]; // 创建一个 n个元素的数组

	srand(time(NULL)); // 随机种子
	for (int i = 0; i < n; i++)
		arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
	return arr;
}


void Swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int * partition(int *arr, int L, int R) {
	int less = L - 1;
	int more = R;
	while (L < more) {
		if (arr[L] < arr[R]) {
			Swap(arr, ++less, L++);
		}
		else if (arr[L] > arr[R])
		{
			Swap(arr, --more, L);
		}
		else
		{
			L++;
		}
	}
	return  new int[] {less + 1, more - 1};
}

void quickSort(int arr[], int L, int R) {
	int *p;
	if (L < R) {
		Swap(arr, L + (rand() % (R - L + 1)), R);
		p = partition(arr, L, R);
		quickSort(arr, L, p[0] - 1);
		quickSort(arr, p[1] + 1, R);
	}
}


int main()
{
	int n = 10;
	int *arr = generateRandomArray(n, 0, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}