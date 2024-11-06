#include "Ctype.h"

void Ctype::Print()
{
    cout << "a=" << ++a << endl;
    cout << "s=" << ++s << endl;
}

Ctype::Ctype(int x)
{
    a = x;
}

int Ctype::s = 0;
