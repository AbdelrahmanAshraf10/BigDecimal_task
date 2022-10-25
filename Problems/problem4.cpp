#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Decimal_Binary(int m);
void number( string prefix , int k );

int main() {
    int decimal ;
    cin>>decimal;
    cout<<Decimal_Binary(decimal) << endl;
    number("00101" , 2 );

    return 0;
}
int Decimal_Binary (int m){
    if (m == 0)
        return 0;
    else
        return (m % 2 + 10 * Decimal_Binary(m / 2));
}
void number( string str , int k ){
    int num;
    num = stoi(str,0,2);
    num = num * (pow(2,k));
    for (int x = 0; x < (pow(2,k)); ++x) {

        cout<<Decimal_Binary(num+x)<<endl;
    }

}
