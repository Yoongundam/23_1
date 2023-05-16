#include <iostream>
#include <unordered_map>
using namespace std;


class GameCharacter {
public:
	int characterCode;
	int characterLevel;
	int characterPower;

public:

	GameCharacter() {}
	GameCharacter(int code, int level, int power) {

		characterCode = code;
		characterLevel = level;
		characterPower = power;
	}
};