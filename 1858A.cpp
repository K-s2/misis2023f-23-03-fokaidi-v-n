// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	int n, i, j, k, a, b, c;
	//std::string a;
	std::vector <char> h;
	std::vector <int> o;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a;
		std::cin >> b;
		std::cin >> c;
		if (c % 2 == 1)
		{
			if (a + 1 > b)
			{
				std::cout << "First"<<std::endl;
			}
			else
			{
				std::cout << "Second" << std::endl;
			}
		}
		else
		{
			if (a > b)
			{
				std::cout << "First" << std::endl;
			}
			else
			{
				std::cout << "Second" << std::endl;
			}
		}

	}

}


