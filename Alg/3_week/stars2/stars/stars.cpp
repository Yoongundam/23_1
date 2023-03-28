#include <iostream>

void printstars(int n) {
	if (n == 0)
	{
		return;
	}
	printstars(n - 1); // 얘를 12번 줄 밑으로 옮기면 역순으로 출력됨.
	for (int i = 0; i < n; i++) {
		std::cout << "*";
	}
	std::cout << std::endl;
}

int main() {
	int n;
	std::cout << "별 개수";
	std::cin >> n;
	printstars(n);
	return 0;
}