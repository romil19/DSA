
/*Suppose you have a string, S, made up of only 'a's and 'b's. 
Write a recursive function that checks if the string was generated using the following rules:

a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'*/

#include<iostream>
using namespace std;

bool check_ab(char input[],int si)//si=startindex
{
    if(input[si]=='\0')
    {
        return true;
    }

    if(input[si]!='a')
    {
        return false;
    }
    if(input[si+1]!='\0' and input[si+2]!='\0')
    {
        if(input[si+1]=='b' && input[si+2]=='b')
        {
            return check_ab(input,si+3);
        }
    }
    return check_ab(input,si+1);
}

bool checkAB(char input[])
{
    bool ans;
    ans=check_ab(input,0);
    return ans;
}

int main()
{
    char input[1000];
    bool ans;
    cin>>input;

    ans=checkAB(input);
    if(ans)
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}