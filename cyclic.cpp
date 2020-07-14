#include<iostream>
#include<math.h>
using namespace std;
long long int cyc(long long int a,int n){
    long long int digit= a%10,a_copy=a;
    a_copy/=10;
    a_copy=digit*pow(10,n-1)+a_copy;
    return a_copy;
}
int main(){
    long long int a,c,a1;
    cin>>a;
    cin>>c;
    a1=a;
    int n=0; 
    while(a1!=(long long int)0){
        a1/=10;
        n++;
    }
    int n1=n;
    while(n--){
        if(a==c){ cout<<"YES"; break;}
        a=cyc(a,n1);
    }
    if(n==-1) cout<<"NO";
    return 0;
}