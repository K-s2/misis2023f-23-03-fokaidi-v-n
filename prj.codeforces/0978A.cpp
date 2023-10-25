#include <iostream>
#include <vector>
#include <algorithm>
 
int main()
{
	int n, i, j, k;
	std::vector <int> h;
	std::vector <int> o;
	std::cin >> n;
	for (i = 0; i < n; i++)
	{
		std::cin >> k;
		h.push_back(k);
	}
	for (int i = h.size() - 1; i >= 0; --i)
	{
		bool found = false;
		for (int j = 0; j < o.size(); ++j)
		{
			if (h[i] == o[j])
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			o.push_back(h[i]);
		}
	}
	std::reverse(o.begin(), o.end());
	std::cout << o.size() << std::endl;
	for (i = 0; i < o.size(); i++)
	{
		std::cout << o[i] << ' ';
	}
}
 
