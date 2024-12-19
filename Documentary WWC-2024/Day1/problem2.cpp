#include<iostream>
using namespace std;
bool check_prime(int);
bool check_prime(int n)
{
    int s=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            s+=1;
        }
    }
    if(s==2)
    return 1;
    else
    return 0;
}
int main()
{
   int n;
   cout<<"Enter a natural number";
   cin>>n;
   int s=check_prime(n);
   if(s==1)
   {
    cout<<n<<" is a prime number";
   }
   else
   {
    cout<<n<<" is not a prime number";
   }
}