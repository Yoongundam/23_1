#include <iostream>
using namespace std;

void SelectionSort(int A[], int n) {
    int i, j, maxIndex;
    for (i = n - 1; i > 0; i--) {
        maxIndex = i;
        for (j = maxIndex - 1; j >= 0; j--)
            if (A[maxIndex] < A[j]) maxIndex = j;
        swap(A[i], A[maxIndex]);
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
    SelectionSort(A, n);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "수행 시간은 : " << duration;

    cout << "\n정렬한 데이터는 : ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;

}