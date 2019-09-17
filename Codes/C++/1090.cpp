#include<bits/stdc++.h>//万能头 
using namespace std;
int a[100000000];//大桶 
int main()
{
    int n,T,i,o=0,Z=0,U=0,Y=0;//U 总体力 Z 一次合并后果子总数目
							  //o 计数(满2合并) Y 合并次数  
    scanf("%d",&n);
    for(i=0;i<n;i++)//数据读入 
    {
        scanf("%d",&T); 
        a[T]++;//记录数据 
    }
    for(i=1;;)//合并部分 
    {
        if(a[i]==0) i++;//防止后方a[i]--搞事情
		 
        a[i]--;//取数 
        Z+=i;//加和 
        o++;//计数 
        if(o==2)//满足合并条件 
        {
            Y++;//增加合并数 
			U+=Z;//计入体力消耗 
            a[Z]++;//合并后新建果子堆 计算个数 
            
			o=0;//重置o 
            Z=0;//重置z
        }
        if(Y==n-1) break;//检查合并是否结束 
    }
    printf("%d",U);//输出总体力 
 } 
//感谢 源代码提供自机房@zwj1
 
