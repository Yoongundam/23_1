#include <iostream>

void countdown(int num) {
    std::cout << num << std::endl;

    if (num == 0) {
        std::cout << "ȭ�� �����ϱ�~~~" << std::endl;
        return;
    }

    countdown(num - 1);
}

int main() {
    countdown(10);

    return 0;
}
