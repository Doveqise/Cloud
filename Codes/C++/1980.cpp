#include <iostream>
using namespace std;
int main(){
    int n,x;
    cin >> n >> x;
    int sum=0;
    int i=10;
    int t=n/i;
    while (t>0){
        t=n/i;
        sum+=t*i/10;
        i*=10;
    }
    i/=100;
    if (n%10>=x) sum+=1;
    if (n/i>x) sum+=i;
    else sum+=n%i+1;
    cout << sum;    
    return 0;
}
