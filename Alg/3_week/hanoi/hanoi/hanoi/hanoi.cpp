#include <iostream>
#include <math.h>
using namespace std;

void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1)
		cout << "����1��" << from << "����" << to << "���οű��.\n";
	else { 
		hanoi_tower(n - 1, from, to, tmp);
		cout << "����" << n << " ��" << from << "����" << to << "���οű��.\n";
		hanoi_tower(n - 1, tmp, from, to);
	}
}
int main()
{
	int n;
	cout << "������ ������?";
	cin >> n;
	hanoi_tower(n, 'A', 'B', 'C');
	cout << "��" << pow(2, n) - 1 << "�� ����Ǿ����ϴ�.\n"; //���� �߰��ϰ� �; ���� �߰���.
	return 0;
}