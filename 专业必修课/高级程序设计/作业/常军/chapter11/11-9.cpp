#include <iostream>
#include <fstream>
#include <string>

void addLineNumbers(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inFile(inputFilename);
    if (!inFile.is_open()) {
        std::cerr << "Unable to open input file: " << inputFilename << std::endl;
        return;
    }

    std::ofstream outFile(outputFilename);
    if (!outFile.is_open()) {
        std::cerr << "Unable to open output file: " << outputFilename << std::endl;
        inFile.close();
        return;
    }

    std::string line;
    int lineNumber = 1;

    while (std::getline(inFile, line)) {
        outFile << std::right << lineNumber << ": " << line << std::endl;
        lineNumber++;
    }

    inFile.close();
    outFile.close();
}

int main() {
    std::string inputFilename;
    std::string outputFilename;

    std::cout << "Enter the input file name: ";
    std::cin >> inputFilename;
    std::cout << "Enter the output file name: ";
    std::cin >> outputFilename;

    addLineNumbers(inputFilename, outputFilename);

    return 0;
}