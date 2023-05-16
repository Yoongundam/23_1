#include "GameCharacter.h"

void print_hash_map(unordered_map<int, GameCharacter>& ch);
void build_hash_map(unordered_map<int, GameCharacter>& hashMap);
void find_hash_map(int key, unordered_map<int, GameCharacter>& hashmap);

int main() {

	unordered_map<int, GameCharacter>Characters;
	build_hash_map(Characters);
	cout << "### ĳ���� ��� ###" << endl;
	print_hash_map(Characters);
	int key;

	while (1) {
		int key;
		cout << "ã�����ϴ� Ű?(-1�� �Է��ϸ� ����)";
		cin >> key;
		if (key == -1)break;
		find_hash_map(key, Characters);

	}
	cout << "������ Ű?";
	cin >> key;
	Characters.erase(key);
	cout << "\n### �ڵ尡" << key << "�� ĳ���� ���� �� ###\n" << endl;
	print_hash_map(Characters);

	return 0;
}

void print_hash_map(unordered_map<int, GameCharacter>& ch) {
	unordered_map<int, GameCharacter>::iterator it;
	for (it = ch.begin(); it != ch.end(); ++it)
	{
		cout << "ĳ���� �ڵ� : " << it->second.characterCode << ", ���� : ";
		cout << it->second.characterLevel << ", �Ŀ� : ";
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
		cout << "## �ڵ尡" << key << "�� ĳ���� �˻� ��� ###" << endl;
		cout << "ĳ���� �ڵ� : " << found->second.characterCode << ", ���� : ";
		cout << found->second.characterLevel << ", �Ŀ� : ";
		cout << found->second.characterPower << endl;
	}
	else cout << "Ű" << key << "�� �ش��ϴ� ĳ���Ͱ� �����ϴ�." << endl;
}

