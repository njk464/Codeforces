#include <iostream>
#include <string>
bool palindrome(std::string p);
main()
{
	std::string p;
	std::cin >> p;
	std::string temp ="";
	if (palindrome(p))
	{
		temp = p[p.length() / 2];
		p.insert(p.length()/2, temp);
		std::cout << p;
		return 0;
	}
	int count = 0;
	int i = 0;
	while ( i < p.length() / 2)
	{
		if (p[i] != p[p.length() - i - 1])
		{
			if (count == 1)
			{
				std::cout << "NA";
				return 0;
			}
			count++;
			temp = p[i];
			std::string r = p;
			r.insert(p.length() - i, temp);
			if (palindrome(r))
			{
				std::cout << r;
				return 0;
			}
			temp = p[p.length() - i - 1];
			p.insert(i, temp);
			if (palindrome(p))
			{
				std::cout << p;
				return 0;
			}
			else
			{
				std::cout << "NA";
				return 0;
			}
		}
		i++;
	}
}
bool palindrome(std::string p)
{
	int i = 0;
	while ( i < p.length() / 2)
	{
		if (p[i] != p[p.length() - i - 1])
			return false;
		i++;
	}
	return true;
}