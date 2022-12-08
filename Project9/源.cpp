#include <stack>
#include <cmath>
#include <iostream>
class Solution {
public:
	std::stack<char> input;//输入的栈
	std::stack<char> output;//输出的栈
	std::stack<char> num;//字符重复次数

	std::string compress(std::string str)//压缩函数
	{

		/*for 循环作用：从低位到高位扫描识别str的每一位str【i】 
		若str【i】为	1.非】（则表示无压缩数据）： 走else 压入input栈里
						2.】（有数据压缩）：走if
		*/

		for (int i = 0;i < str.length();i++)//从低位到高位遍历字符串str，由参数传入
		{
			if (str[i] == ']')
			{//找到要循环的字符，则开始解压缩

				/*
					1.弹出input栈顶附件的循环字符，并压入output
					2.弹出input栈顶附件的次数，并压入num（）
					3.num出栈记录num的大小到number
					4.使用string istem 记录 output里的字符
					5.循环number次将istem压入 input
				*/


				//1.弹出input栈顶附件的循环字符
				while (input.top() != '|')//直到 输入的栈顶为|
				{
					output.push(input.top());//循环将 输入的栈顶 压入 输出的栈里
					input.pop();//将输入栈顶弹出 
				}

				input.pop(); //弹出栈顶的|

				//2.弹出input栈顶附件的次数，并压入num
				while (input.top() != '[')//直到 输入的栈顶为【
				{
					num.push(input.top());//循环将输入的栈顶 压入 num
					input.pop(); //输入的栈顶弹出
				}

				input.pop(); //弹出输入的【

				//3.num出栈记录num的大小到number
				int number = 0;//计算num的实际大小
				while (!num.empty())//直到num为空  栈底为低位 栈顶为高位存储
				{
					number += int(num.top() - '0') * int(pow(10, num.size() - 1));//（num的栈顶-‘0’）*对应次幂int（pow（10，num。size（）-1））
					num.pop();
				}

				//4.使用string istem 记录 output里的字符
				std::string sItem;
				while (!output.empty())
				{
					sItem += output.top();
					output.pop();
				}

				//5.循环number次将istem压入 input
				for (int j = 0;j < number;j++) //循环 number次
				{
					for (int k = 0;k < sItem.length();k++)//将字符串sitem第k个字符从低位到高位压入input栈里
					{
						input.push(sItem[k]);
					}
				}
			}
			else
			{
				input.push(str[i]);//如果没用i则将
			}
		}
			std::string reverseArr;
			while (!input.empty())
			{
				reverseArr += input.top();
				input.pop();
			}

			int size = reverseArr.length();
			char temp;

			for (int i = 0;i < size / 2;i++)
			{
				temp = reverseArr[i];
				reverseArr[i] = reverseArr[size - 1 - i];
				reverseArr[size - 1 - i] = temp;
			}
			return reverseArr;
	
	}

};

int main()
{
	Solution test;
	std::cout<<test.compress("HG[3|B[2|CA]]F");

}