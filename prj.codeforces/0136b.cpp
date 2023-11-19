#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>


std::string thr(int a)
{
	std::string s = "";
	while (a > 0)
	{
		s += std::to_string(a % 3);
		a = a / 3;
	}
	//std::reverse(s.begin(), s.end());
	return s;
}

int p(int q)
{
	int r = 1;
	while (q > 0)
	{
		r = r * 3;
		q = q - 1;
	}
	return r;
}

int main()
{
	int a = 0;
	std::cin >> a;
	int c = 0;
	std::cin >> c;
	int m = std::max(a, c);
	int counter = 0;
	int n = 3;
	while (m > 0)
	{
		m = std::max(a, c);
		m = m / n;
		n = n * 3;
		counter += 1;
	}
	//std::cout << counter;
	std::string s_a = thr(a);
	std::string s_c = thr(c);
	while (s_c.size() > s_a.size())
	{
		s_a = s_a + "0";
	}
	while (s_a.size() > s_c.size())
	{
		s_c = s_c +"0";
	}
	std::string s_b = "";
	int k = 0;
	int mn = s_a.size();
	for (int i = 0; i < mn; i++)
	{
		char c_c = s_c.at(i);
		char c_a = s_a.at(i);
		k = std::stoi(std::string(1, c_c)) - std::stoi(std::string(1, c_a));
		if (k > -1)
		{
			s_b += std::to_string(k%3);
		}
		else
		{
			s_b += std::to_string(k + 3);
		}
	}
	//std::cout << s_b;
	//std::reverse(s_b.begin(), s_b.end());
	int ans= 0;
	for (int i = 0; i < s_b.size(); i++)
	{
		char c_b = s_b.at(i);
		k = std::stoi(std::string(1, c_b));
		//std::cout << c_b << " " << ans << std::endl;
		ans += k * p(i);
	}
	std::cout << ans;

}
