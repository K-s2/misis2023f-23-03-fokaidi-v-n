#include <iostream>
#include <vector>
#include <string>
 
 
int main()
{
	int n = 0;
	std::cin >> n;
	std::string h;
	std::cin.ignore();
	getline(std::cin, h);
	//std::cout << h;
	int x = 0;
	int y = 0;
	int money = 0;
	for (int i = 0; i < n; i++)
	{
		if (h[i] == 'U')
		{
			y += 1;
		}
		else
		{
			x += 1;
		}
		if (x == y)
		{
			money += 1;
		}
	}
	std::cout << money;
}
