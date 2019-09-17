#include<iostream>
using namespace std;
const inline unsigned long long fab(const register unsigned long long n){
	if(n==1||n==2) 
		return 1;
	else 
	{
		cout << fab(n-1)+ fab(n-2)<<endl;
		return fab(n-1)+ fab(n-2);
	}
}
const inline unsigned long long f(const register unsigned long long i,const register unsigned long long n1,const register unsigned long long n2)
{	cout<<i<<endl;
	return i == 1 ? n2 : f(i - 1, n2, n1 + n2);
}
const inline unsigned long long fab0(const register unsigned long long i)
{
	return f(i, 1, 1);//封装为单参数函数 
}
int main(){
	int n;
	cin>>n;
	cout<<fab0(n)<<endl;
	return 0;
}

