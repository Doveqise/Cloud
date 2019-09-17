#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(int x,int y);

int a[10],b[10];

int main()
{
    for (a[0]=1;a[0]<=6;++a[0])
    {
        for (b[0]=1;b[0]<=6;++b[0])
        {
            if (cmp(0,0))
            {
                printf("No irreflexivity:%d %d\n",a[0],b[0]);
            }
            for (a[1]=1;a[1]<=6;++a[1])
            {
                for (b[1]=1;b[1]<=6;++b[1])
                {
                    if (cmp(0,1)&&min(a[0],b[1])>min(a[1],b[0]))
                    {
                        printf("Not the best:%d %d %d %d\n",a[0],b[0],a[1],b[1]);
                    }
                    for (a[2]=1;a[2]<=6;++a[2])
                    {
                        for (b[2]=1;b[2]<=6;++b[2])
                        {
                            if (cmp(0,1)&&cmp(1,2)&&!cmp(0,2))
                            {
                                printf("No transitivity:%d %d %d %d %d %d\n",a[0],b[0],a[1],b[1],a[2],b[2]);
                            }
                            if (!cmp(0,1)&&!cmp(1,0)&&!cmp(1,2)&&!cmp(2,1)&&(cmp(0,2)||cmp(2,0)))
                            {
                                printf("No transitivity of incomparability:%d %d %d %d %d %d\n",a[0],b[0],a[1],b[1],a[2],b[2]);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

bool cmp(int x,int y)
{
    return min(a[x],b[y])==min(a[y],b[x])?a[x]<a[y]:min(a[x],b[y])<min(a[y],b[x]);
}
