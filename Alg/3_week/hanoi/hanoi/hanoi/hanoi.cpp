#include <iostream>
#include <math.h>
using namespace std;

void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1)
		cout << "원판1을" << from << "에서" << to << "으로옮긴다.\n";
	else { 
		hanoi_tower(n - 1, from, to, tmp);
		cout << "원판" << n << " 을" << from << "에서" << to << "으로옮긴다.\n";
		hanoi_tower(n - 1, tmp, from, to);
	}
}
int main()
{
	int n;
	cout << "원반의 개수는?";
	cin >> n;
	hanoi_tower(n, 'A', 'B', 'C');
	cout << "총" << pow(2, n) - 1 << "번 수행되었습니다.\n"; //따로 추가하고 싶어서 직접 추가함.
	return 0;
}