#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<int, string>mapTest;

	mapTest.insert(pair<int, string>(7, "�λ�� ������"));
	mapTest.insert(make_pair(3, "�λ�� ����"));
	mapTest[9] = "�λ�� ����";
	mapTest.insert(make_pair(10, "�λ�� ������"));
	mapTest[8] = "�λ�� ������";
	mapTest.insert(make_pair(1, "�λ�� ������"));
	mapTest[2] = "�λ�� ���ϱ�";
	mapTest[6] = "�λ�� �ؿ�뱸";

	map<int, string>::iterator itr;
	int key;
	while (1) {
		cout << "�˻��ϰ��� �ϴ� �� �Է�: ";
		cin >> key;
		if (key == -1)break;
		itr = mapTest.find(key);
		if (itr != mapTest.end()) {
			cout << itr->first << " : " << itr->second << endl;
		}
		else {
			cout << "�������� ����" << endl;
		}
	}
	return 0;
}