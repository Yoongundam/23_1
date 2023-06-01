#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        int start = commands[i][0] - 1;
        int end = commands[i][1] - 1;
        int k = commands[i][2] - 1;

        vector<int> temp(array.begin() + start, array.begin() + end + 1);
        sort(temp.begin(), temp.end());

        answer.push_back(temp[k]);
    }

    return answer;
}

int main() {
    cout << "19110171_����"<<endl;

    vector<int> array;
    vector<vector<int>> commands;
    int arraySize;
    int commandSize;

    cout << "�迭�� ũ�⸦ �Է��ϼ���: "<<endl;
    cin >> arraySize;

    cout << "�迭�� ��Ҹ� �Է��ϼ���: "<<endl;
    for (int i = 0; i < arraySize; i++) {
        int num;
        cin >> num;
        array.push_back(num);
    }

    cout << "����� ������ �Է��ϼ���: "<<endl;
    cin >> commandSize;

    cout << "����� [i, j, k] �������� �Է��ϼ���: "<<endl;
    for (int i = 0; i < commandSize; i++) {
        vector<int> command(3);
        cin >> command[0] >> command[1] >> command[2];
        commands.push_back(command);
    }

    vector<int> result = solution(array, commands);

    cout << "���: "<<endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}