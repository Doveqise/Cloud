#include<stdio.h>
int main()
{
    int i,c[13],sum;
    char a[13];//����һ������
    for(i=0;i<13;i++)
        scanf("%c",&a[i]);//����ISBN��������
    for(i=0;i<12;i++)//�����е�����ת��Ϊ�����������
        {
            if(i==1||i==5||i==11)
                continue;
            else
                 c[i]=a[i]-48;
    }
    sum=(c[0]*1+c[2]*2+c[3]*3+c[4]*4+c[6]*5+c[7]*6+c[8]*7+c[9]*8+c[10]*9)%11;//����ʶ���룬���丳ֵ��sum
    if(sum==10&&a[12]=='X')
        printf("Right" );//��sum=10��ʶ����ΪX�����ӡ Right
    if((a[12]-48)==sum)//��ascllת��Ϊ�������ݺ�sum��ȣ����ӡRight
        printf("Right");
    else
    {   a[12]=sum+48;//
        if(sum==10&&a[12]!='X')//��sum=10��ʶ���벻ΪX����X����a[12]
            a[12]='X';
        puts(a);//��ӡ�ַ�������
    }
    return 0;

}   
