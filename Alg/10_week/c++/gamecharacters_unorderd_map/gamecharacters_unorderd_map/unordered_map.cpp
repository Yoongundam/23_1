#include "GameCharacter.h"

void print_hash_map(unordered_map<int, GameCharacter>& ch);
void build_hash_map(unordered_map<int, GameCharacter>& hashMap);
void find_hash_map(int key, unordered_map<int, GameCharacter>& hashmap);

int main() {

	unordered_map<int, GameCharacter>Characters;
	build_hash_map(Characters);
	cout << "### 캐릭터 목록 ###" << endl;
	print_hash_map(Characters);
	int key;

	while (1) {
		int key;
		cout << "찾고자하는 키?(-1을 입력하면 종료)";
		cin >> key;
		if (key == -1)break;
		find_hash_map(key, Characters);

	}
	cout << "삭제할 키?";
	cin >> key;
	Characters.erase(key);
	cout << "\n### 코드가" << key << "인 캐릭터 삭제 후 ###\n" << endl;
	print_hash_map(Characters);

	return 0;
}

void print_hash_map(unordered_map<int, GameCharacter>& ch) {
	unordered_map<int, GameCharacter>::iterator it;
	for (it = ch.begin(); it != ch.end(); ++it)
	{
		cout << "캐릭터 코드 : " << it->second.characterCode << ", 레벨 : ";
		cout << it->second.characterLevel << ", 파워 : ";
		cout << it->second.characterPower << endl;
	}
	cout << endl;
}
void build_hash_map(unordered_map<int, GameCharacter>& hashMap) {

	GameCharacter Character1(12, 7, 1000);
	hashMap.insert(unordered_map<int, GameCharacter>::value_type(12, Character1));
	GameCharacter Character2(15, 20, 111000);
	hashMap.insert(make_pair(15, Character2));
	GameCharacter Character3(200, 34, 3345000);
	hashMap.insert(make_pair(200, Character3));
	GameCharacter Character4(600, 70, 4382911);
	hashMap.insert(make_pair(600, Character4));
}

void find_hash_map(int key, unordered_map<int, GameCharacter>& hashmap) {
	auto found = hashmap.find(key);
	if (found != hashmap.end()) {
		cout << "## 코드가" << key << "인 캐릭터 검색 결과 ###" << endl;
		cout << "캐릭터 코드 : " << found->second.characterCode << ", 레벨 : ";
		cout << found->second.characterLevel << ", 파워 : ";
		cout << found->second.characterPower << endl;
	}
	else cout << "키" << key << "에 해당하는 캐릭터가 없습니다." << endl;
}

