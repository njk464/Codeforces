#include <iostream>
#include <string>
#include <stack>

void block_3dfs(int z, int x, int y);
char ***map;
int k, m, n, count = 0;;
int main()
{
	int x, y;
	std::cin >> k >> m >> n;
	map = new char**[k];
	int i = 0;

	for (i; i < k; i++)
	{
		map[i] = new char*[m];
		int j = 0;
		for (j; j < m; j++)
		{
			map[i][j] = new char[n];
			std::string s;
			std::cin >> s;
			int f = 0;
			for(f; f < n; f++)
			{
				map[i][j][f] = s[f];
			}
		}
	}
	std::cin >> x >> y;
	block_3dfs(0, x - 1, y - 1);
	std::cout << count;

}
void block_3dfs(int z, int x, int y)
{
  	if (z < 0 || z >= k || x < 0 || x >= m || y < 0 || y >= n)
    	return;
  	if (map[z][x][y] == '.')
    {
      	map[z][x][y] = 'V';
      	count++;
      	block_3dfs (z - 1, x, y);
      	block_3dfs (z + 1, x, y);
      	block_3dfs (z, x - 1, y);
      	block_3dfs (z, x + 1, y);
      	block_3dfs (z, x, y - 1);
      	block_3dfs (z, x, y + 1);
    }
}