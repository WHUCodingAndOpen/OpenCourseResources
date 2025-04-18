#include <iostream>
#include <string>
int countLetters(std::string &sentence) {
    int count = 0;
    for (int i = 0; i < sentence.length(); i++) {
        if (isalpha(sentence[i])) {
            count++;
        }
    }
    return count;
}
int main() {
    std::string sentence;
    std::cout << "Please enter a sentence in English: ";
    std::getline(std::cin, sentence);
    int letterCount = countLetters(sentence);
    std::cout << "The number of the letter is " << letterCount << std::endl;
    return 0;
}
