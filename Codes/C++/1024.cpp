#include<cstdio>
using namespace std;
int main(){
	double a,b,c,d;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	for(double i=-100.00;i<=100.00;i+=0.01){
		double j=i+0.01;
		double left=a*i*i*i+b*i*i+c*i+d;
		double right=a*j*j*j+b*j*j+c*j+d;
		if(left==0) printf("%.2lf ",left);
		if(right==0) printf("%.2lf ",right);
		if(left*right<0)printf("%.2lf ",(i+j)/2);
	}
	return 0;
} 
