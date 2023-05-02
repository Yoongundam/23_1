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
		Heap(A, i, n); 	// �ʱ����ܰ� 
	for (int i = n; i > 1; i--) {
		//���Ĵܰ�
		swap(A[1], A[i]);  //��Ʈ�͸Ǹ��������ұ�ȯ
		Heap(A, 1, i - 1);
	}
}

void Merge(int A[], int Low, int Mid, int High)
{
	//�Է�: A[Low : Mid] : �����ҹ迭, A[Mid + 1 : High] : ���ĵȵι迭
	//    ���: A[Low : High] : A[Low : Mid]��A[Mid + 1 : High]���պ��Ͽ����ĵȹ迭. 
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
	//�Է�: A[Low : High] : �����ҹ迭,    
	//         Low, High : �����ҿ��Ұ��ִ°�����Ÿ�����ּ�, �ִ��ε���.
	//���: A[Low : High] : ���ĵȹ迭. 
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
	//A = new int[n];
	A = new int[n+1]; //heap ���� �� ���

	//for (int i = 0; i < n; i++)
		//A[i] = rand() % 100;
	for (int i = 1; i <= n; i++) //heap ���� �� ���
		A[i] = rand() % 100;

	//cout << "\n������ �����ʹ� : "; // ����� ����Ǿ����� Ȯ���� �� ���
	//for (int i = 0; i < n; i++) //heap���� �������� ���
		//cout << A[i] << " ";
	//for (int i = 1; i <= n; i++) //heap ���� �� ���
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
	//cout << "SelectionSort ����ð��� " << duration << " ���Դϴ�.\n";
	//cout << "BubbleSort ����ð��� " << duration << " ���Դϴ�.\n";
	//cout << "MergeSort ����ð��� " << duration << " ���Դϴ�.\n";
	cout << "heapSort ����ð��� " << duration << " ���Դϴ�.\n";


	//cout << "\n������ �����ʹ� : "; // ����� ����Ǿ����� Ȯ���� �� ���
	//for (int i = 0; i < n; i++) //heap���� �������� ���
		//cout << A[i] << " ";
	//for (int i = 1; i <= n; i++) //heap ���� �� ���
		//cout << A[i] << " ";
	return 0;
}