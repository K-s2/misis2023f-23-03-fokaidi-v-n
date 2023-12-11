#include <iostream>
#include <cmath>
#include <vector>
 
int main()
{
    int n, w, m,i, k, g, j, d;
    std::cin>>g;
    for (d = 1; d<=g; d++)
    {
        w = 0;
        j = 0;
        std::cin>>n;
        k = n;
        while(n>0)
        {
            n=n/10;
            w += 1;
        }
        std::vector <int> h;
        h.reserve(w);
        for (i = 0; i <w; i++)
        {
            h[i]=k%10;
            k = k/10;
        }
        for (i =0; i < w; i++)
        {   
            if(h[i]!=0)
            {
                j+= 1;
            }
        }std::cout<<j<<std::endl;
        for (i =0; i < w; i++)
        {   
            if( h[i]!=0)
            {
                std::cout<< h[i]*pow(10, i)<<" ";
            }
        }
    }
 
    
}
