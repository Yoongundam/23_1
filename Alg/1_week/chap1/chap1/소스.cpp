#include <iostream>
#include <ctime>
using namespace std;

unsigned long fsum1(int n) {
	unsigned long sum = n * n;
	return sum;
}


unsigned long fsum2(int n) {
	unsigned long sum = 0;
	for (int i = 1; i <= n; i++)
		sum = sum + n;
	return sum;
}


unsigned long fsum3(int n) {
	unsigned long sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			sum = sum + 1;
	}
	return sum;
}

int main(void)
{
	clock_t start, finish;
	int n;
	double duration;
	cout << " n의 값 입력:";
	cin >> n;
	start = clock();
	unsigned long sum = fsum1(n);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << " 결과는 " << sum << " 함수 fsum1 수행시간은 " << duration << " 초입니다.\n";

	start = clock();
	sum = fsum2(n);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << " 결과는 " << sum << " 함수 fsum2 수행시간은 " << duration << " 초입니다.\n";

	start = clock();
	sum = fsum3(n);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << " 결과는 " << sum << " 함수 fsum3 수행시간은 " << duration << " 초입니다.\n";

	return 1;
}
