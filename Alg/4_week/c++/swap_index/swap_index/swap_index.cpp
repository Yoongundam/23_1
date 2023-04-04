#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int n;
    cout << "정렬할 숫자의 개수를 입력하세요: ";
    cin >> n;
    int* arr = new int[n]; // 동적 배열 할당
    cout << "숫자를 입력하세요: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selectionSort(arr, n);
    cout << "정렬된 숫자: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr; // 동적 배열 해제
    return 0;
}
