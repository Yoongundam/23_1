#include <iostream>

void printstars(int n) {
	if (n == 0)
	{
		return;
	}
	printstars(n - 1); // �긦 12�� �� ������ �ű�� �������� ��µ�.
	for (int i = 0; i < n; i++) {
		std::cout << "*";
	}
	std::cout << std::endl;
}

int main() {
	int n;
	std::cout << "�� ����d";
	std::cin >> n;
	printstars(n);
	return 0;
}