#include <iostream>


int main()
{
	int t = 0;
	std::cin >> t;
	for (int w = 0; w < t; w++)
	{
		int counter = 0;
		int p_i = 0;
		int p_j = 0;
		char s;
		s = ' ';
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				std::cin >> s;
				if (s == 'X')
				{
					if ((i > 4) && (j > 4))
					{
						p_i = abs((i % 5) - 4);
						p_j = abs((j % 5) - 4);
						if (p_i * p_j > 15)
						{
							counter += 5;
							continue;
						}
						if (p_i * p_j > 8)
						{
							counter += 4;
							continue;
						}
						if ((p_i > 1) && (p_j > 1))
						{
							counter += 3;
							continue;
						}
						if (p_i * p_j > 0)
						{
							counter += 2;
							continue;
						}
						counter += 1;
						continue;
					}
					if (i > 4)
					{
						p_i = abs((i % 5) - 4);
						p_j = j;
						if (p_i * p_j > 15)
						{
							counter += 5;
							continue;
						}
						if (p_i * p_j > 8)
						{
							counter += 4;
							continue;
						}
						if ((p_i > 1) && (p_j > 1))
						{
							counter += 3;
							continue;
						}
						if (p_i * p_j > 0)
						{
							counter += 2;
							continue;
						}
						counter += 1;
						continue;
					}
					if (j > 4)
					{
						p_i = i;
						p_j = abs((j % 5) - 4);
						if (p_i * p_j > 15)
						{
							counter += 5;
							continue;
						}
						if (p_i * p_j > 8)
						{
							counter += 4;
							continue;
						}
						if ((p_i > 1) && (p_j > 1))
						{
							counter += 3;
							continue;
						}
						if (p_i * p_j > 0)
						{
							counter += 2;
							continue;
						}
						counter += 1;
						continue;
					}
					if ((i <= 4) && (j <= 4))
					{
						p_i = i;
						p_j = j;
						if (p_i * p_j > 15)
						{
							counter += 5;
							continue;
						}
						if (p_i * p_j > 8)
						{
							counter += 4;
							continue;
						}
						if ((p_i > 1) && (p_j > 1))
						{
							counter += 3;
							continue;
						}
						if (p_i * p_j > 0)
						{
							counter += 2;
							continue;
						}
						counter += 1;
						continue;
					}
				}
			}
		}
		std::cout << counter<<std::endl;
	}
}
