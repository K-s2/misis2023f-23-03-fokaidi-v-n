#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
int main()
{
	int n, i, j, k;
	std::string a;
	std::vector <char> h;
	std::vector <int> o;
	std::cin >> n;
	std::cin.ignore();
	j = 0;
	k = 0;
	std::getline(std::cin, a);
	for (char c : a)
	{
		h.emplace_back(c);
	}
	h.emplace_back('f');
	for (i = 0; i < h.size() - 1; i++)
	{
		if (h[i] == h[i + 1] and h[i] == 'x')
		{
			j += 1;
		}
		else if (j > 1)
		{
			j += 1;
			k = k + (j - 2);
			j = 0;
		}
		else
		{
			j = 0;
		}
	}std::cout << k;
}
 
