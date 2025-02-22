#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // 初始化随机数生成器
    std::srand(std::time(0));
    int secretNumber = std::rand() % 100 + 1; // 生成1到100之间的随机数
    int guess;
    bool guessedCorrectly = false;

    std::cout << "猜一个1到100之间的数字：" << std::endl;

    do {
        std::cout << "请输入你的猜测：";
        std::cin >> guess;

        if (guess == secretNumber) {
            std::cout << "恭喜你，猜对了！" << std::endl;
            guessedCorrectly = true;
        } else if (guess < secretNumber) {
            std::cout << "太小了，再试试看！" << std::endl;
        } else {
            std::cout << "太大了，再试试看！" << std::endl;
        }
    } while (!guessedCorrectly);

    return 0;
}