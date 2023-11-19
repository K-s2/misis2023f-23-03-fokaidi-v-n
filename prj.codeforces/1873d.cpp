#include <iostream>
#include <string>
#include <vector>


int main()
{
	int t = 0;
	std::cin >> t;
	for (int w = 0; w < t; w++)
	{
		int n = 0;
		int k = 0;
		std::cin >> n;
		std::cin >> k;
		std::string s;
		std::cin.ignore();
		getline(std::cin, s);
		std::vector <int> h;
		int c = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'B')
			{
				c += 1;
				i += k - 1;
			}
		}
		std::cout << c<< std::endl;
	}
}
