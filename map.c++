#include <iostream>
#include <string>
#include <stack>

void block_dfs(int x, int y);
char *map;
int m, n, rem;
int main()
{
	int x, y, open = 0;
	std::cin >> m >> n >> rem;
	map = new char[m * n];
	int i  = 0;
	for (i; i < m; i++)
	{
		int k = 0;
		std::string s;
		std::cin >> s;
		for (k; k < n; k++)
		{
			map[i * n + k] = s[k];
			if (s[k] == '.')
			{
				open++;
				x = i;
				y = k;
			}
		}
	}
	rem = open - rem;

	block_dfs(x, y);
	i = 0;
	for (i; i < m; i++)
	{
		int k = 0;
		for (k; k < n; k++)
		{
			if (map[i * n + k] == 'H')
				std::cout << '.';
			else
				std::cout << map[i * n + k];
		}
		std::cout << "\n";
	}
	delete[] map;

}
void block_dfs(int x, int y)
{
  	if (x < 0 || x >= m || y < 0 || y >= n)
    	return;
  	if (map[x * n + y] == '.')
    {
      	if (rem-- > 0)
      		map[x * n + y] = 'H';
      	else
      		map[x * n + y] = 'X';
      	block_dfs (x - 1, y);
      	block_dfs (x + 1, y);
      	block_dfs (x, y - 1);
      	block_dfs (x, y + 1);
    }
}