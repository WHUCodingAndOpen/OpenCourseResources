#include <iostream>
using namespace std;
class Ctype
{
private:
  int a;
  static int s; // 定义私有的静态数据成员s
public:
  void Print();
  Ctype(int x = 0);
};
