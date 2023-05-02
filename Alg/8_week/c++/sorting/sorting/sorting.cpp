#include <iostream>
using namespace std;

void MergeSort(int A[], int Low, int High) {
	int Mid;
	if (Low < High) {
		Mid = (Low + High) / 2;
		MergeSort(A, Low, Mid);
		MergeSort(A, Mid + 1, High);

	}
}

void SelectionSort(int A[], int n) {
	int i, j, maxIndex;
	for (i = n - 1; i > 0; i--) {
		maxIndex = i;
		for (j = maxIndex - 1; j >= 0; j--)
			if (A[maxIndex] < A[j])   maxIndex = j;
		swap(A[i], A[maxIndex]);
	}
}

void BubbleSort(int A[], int n) {
	//�Է�: A[0 : n-1] : �����ҿ��Ұ��ִ¹迭,  n : �����ҿ����ǰ���.//���: A[0 : n-1] : ���ĵȹ迭.
	int i, NumKeys;
	bool Sorted;
	Sorted = false;
	NumKeys = n;
	while (!Sorted) {
		Sorted = true;
		for (i = 1; i < NumKeys; i++)
			if (A[i - 1] > A[i]) {
				swap(A[i - 1], A[i]);
				Sorted = false;
			}//end of  
		NumKeys--;
	} //end of  while  
}

int main() {
	int n, * A;

	srand((unsigned int)time(NULL));
	cout << "�������� ���� �Է�: ";
	cin >> n;
	A = new int[n];

	for (int i = 0; i < n; i++)
		A[i] = rand() % 100;

	cout << "\n������ �����ʹ� : ";
	//for (int i = 0; i < n; i++)
		//cout << A[i] << " ";

	clock_t start, finish;
	double duration;

	start = clock();
	SelectionSort(A, n);
	//BubbleSort(A, n);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	//cout << "SelectionSort ����ð��� " << duration << " ���Դϴ�.\n";
	cout << "BubbleSort ����ð��� " << duration << " ���Դϴ�.\n";


	//cout << "\n������ �����ʹ� : ";
	//for (int i = 0; i < n; i++)
		//cout << A[i] << " ";
	return 0;
}