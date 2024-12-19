#include<iostream>
using namespace std;
int sum_of_natural_number(int);
int sum_of_natural_number(int a)
{
    int sum=0;
    for(int i=1;i<=a;i++)
    {
        sum=sum+i;
    }
    return sum;
}
int main()
{
   int n;
   cout<<"Enter a natural number";
   cin>>n;
   cout<<"Sum of "<<n<<" natural number is "<<sum_of_natural_number(n);
}