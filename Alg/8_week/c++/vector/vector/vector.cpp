#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	vector<string> list(10);
	int n;
	string data;

	cout << "�������� ����?";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> data;
		list.push_back(data);
	}
	sort(list.begin(), list.end(), greater<string>());

	vector<string>::iterator it;
	it = list.begin();

	cout << "���ĵ� ���\n";
	for (it = list.begin(); it != list.end(); it++)
		cout << *it << " ";
	return 0;
}