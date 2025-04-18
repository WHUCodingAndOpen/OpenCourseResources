#include <iostream>
using namespace std;

void connectStr(const char *input1, const char *input2, char **out)
{
    size_t count1 = 0;
    size_t count2 = 0;
    while (input1[count1] != '\0')
        count1++;
    while (input2[count2] != '\0')
        count2++;

    size_t outputSize = count1 + count2 + 1;
    *out = new char[outputSize]{};

    size_t step = 0;
    for (auto i = 0; i < count1; i++)
    {
        (*out)[step++] = input1[i];
    }
    for (auto i = 0; i < count2; i++)
    {
        (*out)[step++] = input2[i];
    }
    (*out)[step] = '\0';

}

int main()
{


    char input1[] = "Hello,";
    char input2[] = "world!!!";
    char* output = nullptr;
    connectStr(input1,input2,&output);

    size_t i = 0;
    while(output[i]!='\0'){
        putchar(output[i++]);
    }
    

    return 0;
}
