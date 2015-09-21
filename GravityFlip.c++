#include <stdio.h>
#include <stdlib.h> 
#include <map>

int main(void) 
{
	std::map<int,int> mymap;
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
    		int e;
            scanf("%d", &e);
            mymap[e]++;
    }
    int r;
    for (auto rit = mymap.cbegin(); rit != mymap.cend(); ++rit)
    {
    	int q;
        for (q = 0; q < rit->second; q++)
		    printf("%d ", rit->first);
    }
    return 0;
}