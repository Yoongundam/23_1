#include <iostream>
using namespace std;

void bubblesort(int A[], int n) {
	int i, Numkeys;
	bool Sorted;

	Sorted = false;
	Numkeys = n;
	while (!Sorted) {
		for (i = 1; i < Numkeys; i++)
			if (A[i - 1] > A[i]) {
				swap(A[i - 1], A[i]);
				Sorted = false;
			}
		Numkeys--;
	}
}

int main() {
    int n, * A;

    srand((unsigned int)time(NULL));

    cout << "데이터의 개수 입력 : ";
    cin >> n;
    A = new int[n];

    for (int i = 0; i < n; i++)
        A[i] = rand() % 100;

    cout << n << "\n생성한 데이터는 : ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    clock_t start, finish;
    double duration;

    start = clock();
    bubblesort(A, n);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "수행 시간은 : ";

    cout << "\n정렬한 데이터는 : ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}