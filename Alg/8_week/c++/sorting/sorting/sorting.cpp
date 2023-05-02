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
	//입력: A[0 : n-1] : 정렬할원소가있는배열,  n : 정렬할원소의개수.//출력: A[0 : n-1] : 정렬된배열.
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
	cout << "데이터의 개수 입력: ";
	cin >> n;
	A = new int[n];

	for (int i = 0; i < n; i++)
		A[i] = rand() % 100;

	cout << "\n생성한 데이터는 : ";
	//for (int i = 0; i < n; i++)
		//cout << A[i] << " ";

	clock_t start, finish;
	double duration;

	start = clock();
	SelectionSort(A, n);
	//BubbleSort(A, n);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	//cout << "SelectionSort 수행시간은 " << duration << " 초입니다.\n";
	cout << "BubbleSort 수행시간은 " << duration << " 초입니다.\n";


	//cout << "\n정렬한 데이터는 : ";
	//for (int i = 0; i < n; i++)
		//cout << A[i] << " ";
	return 0;
}