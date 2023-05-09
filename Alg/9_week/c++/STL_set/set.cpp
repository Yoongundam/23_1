#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	set<string> s;
	s.insert("c1"); s.insert("xy2");
	s.insert("ch2"); s.insert("be2");
	s.insert("s1"); s.insert("ff1");
	s.insert("dd1"); s.insert("tt1");
	s.insert("g1"); s.insert("tt2");
	s.insert("kc1"); s.insert("rf1");

	set<string>::iterator itr;
	string key;
	while (1) {
		cin >> key;
		if (key == "exit")break;
		itr = s.find(key);
		if (itr != s.end()) {
			cout << *itr << " : 존재 " << endl;
		}
		else {
			cout << "존재하지 않음" << endl;
		}
	}
	return 0;
}