#include <iostream>
int twoPow(int s, int e);
int main()
{
	int n, m;
	std::cin >> n >> m;
	int count = 0;
	while (n != m)
	{
		if (n > m)
		{
			n--;
			count++;
		}
		else if (n == 1 || n == 2 || twoPow(n,m) < twoPow(n-1,m))
		{
			n*=2;
			count++;
		}
		else
		{
			n--;
			count++;
		}
		// std::cout << n <<"\n";
	}
	std::cout << count;
}
int twoPow(int s, int e)
{
	while ( s < e )
	{
		s*=2;
	}
	return s;
}