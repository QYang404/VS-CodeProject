#include<iostream>
#include<string>
using namespace std;
int main()
{
    //1.整型
    int a = 0;
    cout << " 给整型a赋值为"<< endl;
    cin >> a;
    cout << " 整型a的值为: " << a << endl;
    //2.浮点型
    float b =0.0f;
    cout << " 给浮点型b赋值为"<< endl;
    cin >> b;
    cout << " 浮点型b的值为: " << b << endl;
    //3.字符型:
    char ch = 'a';
    cout << " 给字符型ch赋值为"<< endl;
    cin >> ch;
    cout << " 字符型ch的值为: " << ch << endl;
    //4.字符串型
    string str = "Hello";
    cout << " 给字符串型str赋值为"<< endl;
    cin >> str;
    cout << " 字符串型str的值为: " << str << endl;
    //5.布尔型
    bool flag = true;
    cout << " 给布尔型flag赋值为"<< endl;
    cin >> flag;
    cout << " 布尔型flag的值为: " << flag << endl;
    system("pause");
    return 0;
}