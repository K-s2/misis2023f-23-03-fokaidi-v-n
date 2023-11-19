#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	int n, t;
	//std::string a;

	std::cin >> t;
	for (int j = 0; j < t; j++)
	{

		int a = 0;
		int k = 1;
		std::cin >> a;
		int b = 0;
		std::cin >> b;
		std::cin.ignore();
		int s = a + b;
		std::string str;
		getline(std::cin, str);
		if ((a % 2 == 1) && (b % 2 == 1))
		{
			std::cout << -1 << std::endl;
			continue;
		}
		if ((s % 2 == 1) && (str[s/2] == '?'))
		{
			if (a % 2 == 1)
			{
				str[s / 2] = '0';
			}
			if (b % 2 == 1)
			{
				str[s / 2] = '1';
			}
		}
		for (int i = 1; i < s + 1; i++)
		{
			if (str[i - 1] != str[s - i] and str[i - 1] != '?' and str[s - i] != '?')
			{
				std::cout << -1 << std::endl;
				k = i;
				break;

			}
			if (str[i - 1] == '?' and str[s - i] != '?')
			{
				str[i - 1] = str[s - i];
			}
		}
		if (str[k - 1] != str[s - k] && str[k - 1] != '?' and str[s - k] != '?')
		{
			continue;
		}
		for (int i = 0; i < s; i++)
		{
			if (str[i] == '0')
			{
				a -= 1;
			}
			if (str[i] == '1')
			{
				b -= 1;
			}
		}
		for (int i = 1; i < s + 1; i++)
		{
			if ((str[i - 1] == str[s - i]) && (str[i - 1] == '?'))
			{
				if (a > 0)
				{
					str[i - 1] = '0';
					str[s - i] = '0';
					a -= 2;
				}
				else if (b > 1) {
					str[i - 1] = '1';
					str[s - i] = '1';
					b -= 2;
				}
			}
		}
		if ((a != 0) && (b != 0)) {
			std::cout<<-1<<std::endl;
			continue;
		}
		std::cout << str << std::endl;
	}

}
