#include <iostream>
#include <string>

int main()
{
	int t = 0;
	std::cin >> t;
	for (int w = 0; w < t; w++)
	{
		int m = 0;
		int c = 0;
		int l = 0;
		std::string s;
		int n = 0;
		int ch = 0;
		std::cin >> n;
		char p = 'e';
		std::cin >> p;
		std::cin.ignore();
		std::getline(std::cin, s);
		if (p == 'g')
		{
			std::cout << 0 << std::endl;
			continue;

		}
		s = s+s;
		//std::cout << s;
		for (int i = 0; i < 2*n; i++)
		{
			if ((i < n)&&(s[i]==p))
			{
				//std::cout << 2;
				ch += 1;
			}
			if ((ch == 1)&& (i < n) && (s[i] == p))
			{
				l = i;
			}
			if ((ch > 0) && (s[i] == 'g'))
			{
				//std::cout << 5;
				m = std::max(m, i - l);
				ch = 0;
			}
		}
		std::cout << m << std::endl;
	}
}
