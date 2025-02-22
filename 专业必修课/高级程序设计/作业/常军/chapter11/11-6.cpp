#include <iostream>
#include <fstream>
#include <iomanip>

class Dog
{
private:
    double weight;
    int age;

public:
    Dog() : weight(0), age(0) {}
    Dog(double w, int a) : weight(w), age(a) {}

    void setWeight(double w) { weight = w; }
    void setAge(int a) { age = a; }

    double getWeight() const { return weight; }
    int getAge() const { return age; }

    void print() const
    {
        std::cout << "Weight: " << weight << ", Age: " << age << std::endl;
    }
};

void writeDogToFileText(const Dog &dog, const std::string &filename)
{
    std::ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << dog.getWeight() << " " << dog.getAge() << std::endl;
        outFile.close();
    }
    else
    {
        std::cerr << "Unable to open file." << std::endl;
    }
}

void readDogFromFileText(Dog &dog, const std::string &filename)
{
    std::ifstream inFile(filename);
    if (inFile.is_open())
    {
        double weight;
        int age;
        inFile >> weight >> age;
        dog.setWeight(weight);
        dog.setAge(age);
        inFile.close();
    }
    else
    {
        std::cerr << "Unable to open file." << std::endl;
    }
}

void writeDogToFileBinary(const Dog &dog, const std::string &filename)
{
    std::ofstream outFile(filename, std::ios::binary);
    if (outFile.is_open())
    {
        outFile.write(reinterpret_cast<const char *>(&dog), sizeof(Dog));
        outFile.close();
    }
    else
    {
        std::cerr << "Unable to open file." << std::endl;
    }
}

void readDogFromFileBinary(Dog &dog, const std::string &filename)
{
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile.is_open())
    {
        inFile.read(reinterpret_cast<char *>(&dog), sizeof(Dog));
        inFile.close();
    }
    else
    {
        std::cerr << "Unable to open file." << std::endl;
    }
}

int main()
{
    Dog dog1(5, 10);
    Dog dog2;

    // Text mode
    writeDogToFileText(dog1, "dog1_text.txt");
    readDogFromFileText(dog2, "dog1_text.txt");
    std::cout << "Dog2 after reading from text file: ";
    dog2.print();

    // Binary mode
    writeDogToFileBinary(dog1, "dog1_binary.bin");
    readDogFromFileBinary(dog2, "dog1_binary.bin");
    std::cout << "Dog2 after reading from binary file: ";
    dog2.print();

    return 0;
}