#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<int, string>mapTest;

	mapTest.insert(pair<int, string>(7, "부산시 수영구"));
	mapTest.insert(make_pair(3, "부산시 남구"));
	mapTest[9] = "부산시 동구";
	mapTest.insert(make_pair(10, "부산시 영도구"));
	mapTest[8] = "부산시 금정구";
	mapTest.insert(make_pair(1, "부산시 수영구"));
	mapTest[2] = "부산시 사하구";
	mapTest[6] = "부산시 해운대구";

	map<int, string>::iterator itr;
	int key;
	while (1) {
		cout << "검색하고자 하는 값 입력: ";
		cin >> key;
		if (key == -1)break;
		itr = mapTest.find(key);
		if (itr != mapTest.end()) {
			cout << itr->first << " : " << itr->second << endl;
		}
		else {
			cout << "존재하지 않음" << endl;
		}
	}
	return 0;
}