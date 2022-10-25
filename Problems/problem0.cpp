#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input,output;
    getline(cin,input);
    for(int i=0;i<input.length();i++)
    {
        if(input[i]!=' ')
        {
            output+=input[i];
        }
        else if (input[i]==' ' && input[i+1]!=' ')
        {
            output+=input[i];
        }
    }
    cout<<output;

}
