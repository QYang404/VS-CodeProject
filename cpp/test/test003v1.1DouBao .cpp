#include<iostream>
#include<string>
#include<limits>   // 【新增 v1.1】清空输入缓冲区要用到 numeric_limits，必须包含此头文件
using namespace std;

/* ============================================================
 * 【新增 v1.1】安全输入函数模板 safeInput
 * ------------------------------------------------------------
 * 作用：对任意基础类型（int / float / char / string / bool 等）做安全输入。
 *      当输入类型不匹配时（例如给 int 输入字母 f104），cin 会被置上错误标志
 *      （failbit）而“卡死”，导致后面所有输入全部失效。
 *      本函数会自动完成下面 3 步，并让用户重新输入，直到正确为止：
 *        1. cin.clear()      —— 清除错误标志，把输入流“唤醒”；
 *        2. cin.ignore(...)  —— 丢弃缓冲区里残留的错误字符；
 *        3. 重新 cin >> var  —— 提示用户重新输入。
 *  参数：var  —— 要赋值的变量（引用传递，才能把结果带出去）；
 *        tip  —— 输入前显示的提示文字。
 * ============================================================ */
template<typename T>
void safeInput(T& var, const string& tip)
{
	cout << tip << endl;
	while (!(cin >> var))   // cin >> var 读取失败时返回 false，进入循环
	{
		cin.clear();        // 第1步：清除 failbit 错误标志，恢复输入流正常状态
		// 第2步：丢弃缓冲区中从当前位置直到换行符 '\n' 为止的所有字符
		// numeric_limits<streamsize>::max() 表示“不限制字符数量”
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " 输入无效，请重新输入：" << endl;   // 提示用户重新输入
	}
	/* 【新增 v1.1】读取成功后，再清空本行剩余的字符。
	 * 例如给 float 输入 3.15f 时，cin 只取走 3.15，残留的 'f' 会被这里清掉，
	 * 避免它被下一次输入（尤其是字符型 char）误读、导致跳过输入。 */
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    //1.整型
    int a = 0;
    safeInput(a, " 给整型a赋值为");   // 【新增 v1.1】用 safeInput 替换原来的 cin >> a，输错可自动重试
    cout << " 整型a的值为: " << a << endl;
    //2.浮点型
    float b =0.0f;
    safeInput(b, " 给浮点型b赋值为");   // 【新增 v1.1】替换 cin >> b
    cout << " 浮点型b的值为: " << b << endl;
    //3.字符型:
    char ch = 'a';
    safeInput(ch, " 给字符型ch赋值为");   // 【新增 v1.1】替换 cin >> ch
    cout << " 字符型ch的值为: " << ch << endl;
    //4.字符串型
    string str = "Hello";
    safeInput(str, " 给字符串型str赋值为");   // 【新增 v1.1】替换 cin >> str
    cout << " 字符串型str的值为: " << str << endl;
    //5.布尔型
    bool flag = true;
    // 【新增 v1.1】替换 cin >> flag；bool 型默认只认数字：输入 1 表示 true，0 表示 false
    safeInput(flag, " 给布尔型flag赋值为(输入1表示true,0表示false)");
    cout << " 布尔型flag的值为: " << flag << endl;
    system("pause");
    return 0;
}
