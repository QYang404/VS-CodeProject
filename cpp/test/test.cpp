#include<iostream>
using namespace std;
int num = 10;
int main()
{
    cout << "num=" << num << endl;
    cout << "int所占空间为:" << sizeof(int) << "字节" << endl;
    cout << "num所占空间为:" << sizeof(num) << "字节" << endl;
    system("pause");
    return 0;
}
