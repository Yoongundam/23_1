#include <iostream>
using namespace std;
#define NUM_OF_KEYS 100000

void Heap(int A[], int k, int n) {
	int left, right, smaller;
	left = 2 * k;
	right = 2 * k + 1;
	if (right <= n)
		if (A[left] < A[right])
			smaller = left;
		else smaller = right;
	else if (left <= n) smaller = left;
	else return;
	if (A[smaller] < A[k]) {
		swap(A[k], A[smaller]);
		Heap(A, smaller, n);
	}
}

void heapSort(int A[], int n)
{
	for (int i = n / 2; i > 0; i--)
		Heap(A, i, n); 	// 초기힙단계 
	for (int i = n; i > 1; i--) {
		//정렬단계
		swap(A[1], A[i]);  //루트와맨마지막원소교환
		Heap(A, 1, i - 1);
	}
}

void Merge(int A[], int Low, int Mid, int High)
{
	//입력: A[Low : Mid] : 정렬할배열, A[Mid + 1 : High] : 정렬된두배열
	//    출력: A[Low : High] : A[Low : Mid]와A[Mid + 1 : High]를합병하여정렬된배열. 
	int B[NUM_OF_KEYS];
	int i, LeftPtr, RightPtr, BufPtr;
	LeftPtr = Low;
	RightPtr = Mid + 1;
	BufPtr = Low;
	while (LeftPtr <= Mid && RightPtr <= High) {
		if (A[LeftPtr] <= A[RightPtr])
			B[BufPtr++] = A[LeftPtr++];
		else B[BufPtr++] = A[RightPtr++];
	} //end of  while
	if (LeftPtr > Mid) {
		for (i = RightPtr; i <= High; i++)
			B[BufPtr++] = A[i];
	}
	else {
		for (i = LeftPtr; i <= Mid; i++)
			B[BufPtr++] = A[i];
	}
	for (i = Low; i <= High; i++)
		A[i] = B[i];
}

void MergeSort(int A[], int Low, int High) {
	//입력: A[Low : High] : 정렬할배열,    
	//         Low, High : 정렬할원소가있는곳을나타내는최소, 최대인덱스.
	//출력: A[Low : High] : 정렬된배열. 
	int Mid;
	if (Low < High) {
		Mid = (Low + High) / 2;
		MergeSort(A, Low, Mid);
		MergeSort(A, Mid + 1, High);
		Merge(A, Low, Mid, High);
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
	//A = new int[n];
	A = new int[n+1]; //heap 정렬 시 사용

	//for (int i = 0; i < n; i++)
		//A[i] = rand() % 100;
	for (int i = 1; i <= n; i++) //heap 정렬 시 사용
		A[i] = rand() % 100;

	//cout << "\n생성한 데이터는 : "; // 제대로 수행되었는지 확인할 때 사용
	//for (int i = 0; i < n; i++) //heap제외 나머지에 사용
		//cout << A[i] << " ";
	//for (int i = 1; i <= n; i++) //heap 정렬 시 사용
		//cout << A[i] << " ";

	clock_t start, finish;
	double duration;

	start = clock();
	//SelectionSort(A, n);
	//BubbleSort(A, n);
	//MergeSort(A, 0, n - 1);
	heapSort(A, n);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	//cout << "SelectionSort 수행시간은 " << duration << " 초입니다.\n";
	//cout << "BubbleSort 수행시간은 " << duration << " 초입니다.\n";
	//cout << "MergeSort 수행시간은 " << duration << " 초입니다.\n";
	cout << "heapSort 수행시간은 " << duration << " 초입니다.\n";


	//cout << "\n정렬한 데이터는 : "; // 제대로 수행되었는지 확인할 때 사용
	//for (int i = 0; i < n; i++) //heap제외 나머지에 사용
		//cout << A[i] << " ";
	//for (int i = 1; i <= n; i++) //heap 정렬 시 사용
		//cout << A[i] << " ";
	return 0;
}