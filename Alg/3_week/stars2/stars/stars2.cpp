#include <iostream>
using namespace std;

void print(int n) {
    if (n == 1) {
        cout << "*";
        return;
    }
    print(n - 1);
    cout << "*";
}

void printstars(int n) {
    if (n == 0) {
        return;

    }
    printstars(n - 1);
    print(n);
    cout << endl;
}

int main() {
    int n;
    cout << "º° °³¼ö: ";
    cin >> n;
    printstars(n);
    return 0;
}