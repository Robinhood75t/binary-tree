#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number: ";
    cin>>n;
    int original = n;
    int result = 0;
    while(n>0)
    {
        int lastdigit = n%10;
        result += pow(lastdigit,3);
        n = n/10;
    }
    if(original == result)
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
     return 0;
}