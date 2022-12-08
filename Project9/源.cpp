#include <stack>
#include <cmath>
#include <iostream>
class Solution {
public:
	std::stack<char> input;//�����ջ
	std::stack<char> output;//�����ջ
	std::stack<char> num;//�ַ��ظ�����

	std::string compress(std::string str)//ѹ������
	{

		/*for ѭ�����ã��ӵ�λ����λɨ��ʶ��str��ÿһλstr��i�� 
		��str��i��Ϊ	1.�ǡ������ʾ��ѹ�����ݣ��� ��else ѹ��inputջ��
						2.����������ѹ��������if
		*/

		for (int i = 0;i < str.length();i++)//�ӵ�λ����λ�����ַ���str���ɲ�������
		{
			if (str[i] == ']')
			{//�ҵ�Ҫѭ�����ַ�����ʼ��ѹ��

				/*
					1.����inputջ��������ѭ���ַ�����ѹ��output
					2.����inputջ�������Ĵ�������ѹ��num����
					3.num��ջ��¼num�Ĵ�С��number
					4.ʹ��string istem ��¼ output����ַ�
					5.ѭ��number�ν�istemѹ�� input
				*/


				//1.����inputջ��������ѭ���ַ�
				while (input.top() != '|')//ֱ�� �����ջ��Ϊ|
				{
					output.push(input.top());//ѭ���� �����ջ�� ѹ�� �����ջ��
					input.pop();//������ջ������ 
				}

				input.pop(); //����ջ����|

				//2.����inputջ�������Ĵ�������ѹ��num
				while (input.top() != '[')//ֱ�� �����ջ��Ϊ��
				{
					num.push(input.top());//ѭ���������ջ�� ѹ�� num
					input.pop(); //�����ջ������
				}

				input.pop(); //��������ġ�

				//3.num��ջ��¼num�Ĵ�С��number
				int number = 0;//����num��ʵ�ʴ�С
				while (!num.empty())//ֱ��numΪ��  ջ��Ϊ��λ ջ��Ϊ��λ�洢
				{
					number += int(num.top() - '0') * int(pow(10, num.size() - 1));//��num��ջ��-��0����*��Ӧ����int��pow��10��num��size����-1����
					num.pop();
				}

				//4.ʹ��string istem ��¼ output����ַ�
				std::string sItem;
				while (!output.empty())
				{
					sItem += output.top();
					output.pop();
				}

				//5.ѭ��number�ν�istemѹ�� input
				for (int j = 0;j < number;j++) //ѭ�� number��
				{
					for (int k = 0;k < sItem.length();k++)//���ַ���sitem��k���ַ��ӵ�λ����λѹ��inputջ��
					{
						input.push(sItem[k]);
					}
				}
			}
			else
			{
				input.push(str[i]);//���û��i��
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