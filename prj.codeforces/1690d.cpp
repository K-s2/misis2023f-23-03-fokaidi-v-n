#include <iostream>
#include <string>

int main()
{
	int t = 0;
	std::cin >> t;
	for (int w = 0; w < t; w++)
	{
		int n = 0;
		std::cin >> n;
		int k = 0;
		std::cin >> k;
		std::cin.ignore();
		std::string s;
		std::getline(std::cin, s);
		char f = s[0];
		char l = s[k-1];
		int c = 0;
		int p = 0;
		for (int i = 0; i < k; i++)
		{
			if (s[i] == 'B')
			{
				p += 1;
			}
		}
		c = std::max(c, p);
		for (int i = k ; i < n ; i++)
		{
			if ((s[i] == 'B'))
			{
				if (s[i - k] == 'W')
				{
					p += 1;
				}
			}
			if ((s[i] == 'W'))
			{
				if (s[i - k] == 'B')
				{
					p -= 1;
				}
			}
			c = std::max(c, p);
		}
		if (c >= k)
		{
			std::cout << 0 << std::endl;
		}
		else
		{
			std::cout << k - c << std::endl;
		}
	}
}
