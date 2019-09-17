const int Size=2.2e6;
char buf[Size],*pp=buf-1;

inline int in(){
    while(*++pp<'-');
    register int x=*pp&15;
    while(*++pp>'-')x=x*10+(*pp&15);
    return x;
}
void out(register int x){
    if(x>9)out(x/10);
    *++pp=x%10|'0';
}
for(pp=buf-1,i=0;i<n;++i)
        out(ans[i]),*++pp='\n';
fread(buf,1,Size,stdin);
fwrite(buf,1,pp-buf+1,stdout);
