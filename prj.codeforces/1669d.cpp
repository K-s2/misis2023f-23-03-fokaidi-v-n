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
		std::string s;
		std::string ch;
		int c = 0;
		int o = 0;
		std::cin.ignore();
		std::getline(std::cin, s);
		s = 'W' + s + 'W';
		for (int i = 0; i < n+2; i++)
		{
			//std::cout << ch << std::endl;
			if (o == 1)
			{
				ch += s[i];
			}
			if ((s[i] == 'W') && (o == 1))
			{
				o = 0;
				if (((std::count(ch.begin(), ch.end(), 'R') == 0) && ((std::count(ch.begin(), ch.end(), 'B') != 0))) || (((std::count(ch.begin(), ch.end(), 'B') == 0) && ((std::count(ch.begin(), ch.end(), 'R') != 0)))))
				{
					c += 1;
					break;
				}
			}
			if (s[i] == 'W')
			{
				o += 1;
			}
			if ((s[i] == 'W')&&((std::count(ch.begin(), ch.end(), 'W'))>0))
			{
				ch.clear();
			}
		}
		if (c > 0)
		{
			std::cout << "NO" << std::endl;
		}
		else
		{
			std::cout << "YES"<<std::endl;
		}
	}
}
