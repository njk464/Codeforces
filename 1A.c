#include <stdio.h>
main()
{
	unsigned long n, m, b;
	scanf("%lu", &n);
	scanf("%lu", &m);
	scanf("%lu", &b);
	if ( n % b == 0 && m % b == 0)
	{
		printf("%lu", (n * m) / (b * b));
		return 0;
	}
	if (n % b == 0)
	{
		printf ("%lu", (n / b) * (m / b + 1));
		return 0;
	}
	if (m % b == 0)
	{
		printf ("%lu", (m / b) * (n / b + 1));
		return 0;
	}
	if (b > n && b > m)
	{
		printf("%d", 1);
		return 0;
	}
	if (b > n)
	{
		printf("%lu", m / b);
		return 0;
	}
	if (b > m)
	{
		printf("%lu", n / b);
		return 0;
	}
	printf("%lu", (n / b + 1) * (m / b + 1));
	return 0;

}