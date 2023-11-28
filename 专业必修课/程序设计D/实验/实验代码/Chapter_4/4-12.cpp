#include <iostream>
#include <string>
using namespace std;
class DataType {
public:
    DataType() = default;
    DataType(char c, int i, float f) : charData(c), intData(i), floatData(f) {}
    ~DataType() = default;

    void displayData() {
        cout << "字符型数据: " << charData << endl;
        cout << "整型数据: " << intData << endl;
        cout << "浮点型数据: " << floatData << endl;
    }
private:
    char charData;
    int intData;
    float floatData;
};
int main() {
    DataType data('A', 42, 3.14);
    data.displayData();
    return 0;
}
