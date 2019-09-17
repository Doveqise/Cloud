#include<stdio.h>
int main()
{
    int i,c[13],sum;
    char a[13];//定义一个数组
    for(i=0;i<13;i++)
        scanf("%c",&a[i]);//输入ISBN号码数组
    for(i=0;i<12;i++)//将其中的数字转化为整形数据输出
        {
            if(i==1||i==5||i==11)
                continue;
            else
                 c[i]=a[i]-48;
    }
    sum=(c[0]*1+c[2]*2+c[3]*3+c[4]*4+c[6]*5+c[7]*6+c[8]*7+c[9]*8+c[10]*9)%11;//计算识别码，将其赋值给sum
    if(sum==10&&a[12]=='X')
        printf("Right" );//若sum=10且识别码为X，则打印 Right
    if((a[12]-48)==sum)//若ascll转化为整形数据和sum相等，则打印Right
        printf("Right");
    else
    {   a[12]=sum+48;//
        if(sum==10&&a[12]!='X')//若sum=10且识别码不为X，则将X赋给a[12]
            a[12]='X';
        puts(a);//打印字符串数组
    }
    return 0;

}   
