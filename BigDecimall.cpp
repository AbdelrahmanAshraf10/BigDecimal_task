#include<bits/stdc++.h>
using namespace std;
#include "BigDecimall.h"

BigDecimall::BigDecimall()
{

}
BigDecimall::BigDecimall(string str){
    int a , counter = 0;
    if(str[0] == '-'){
        s ='-';
    }
    else
        s = '+';

    for (int x = 1; x< str.size();x++){
            a = str[x] - 48;
            if(a == 0 && counter == 0){
                continue;


            }
            else{
                counter = 1;
                vect.push_back(a);

    }
}
}
BigDecimall::BigDecimall(int num)
{
    if (num < 0){
        num*=-1;
        vect.push_back(num);

    }
    else if (num == 0){
        vect.push_back(0);

    }
    else if (num > 0){
            while (num){
                int a = num % 10;
                num /= 10;
                vect.push_back (a);
            }

    }
    reverse(vect.begin(),vect.end());
}
BigDecimall BigDecimall :: operator + (BigDecimall b1){
    BigDecimall b2;
    int num, temp,xnxx;
    int c = 0;
    reverse(vect.begin(),vect.end());
    reverse(b1.vect.begin(),b1.vect.end());
    if (vect.size() > b1.vect.size()){
            temp = vect.size() - b1.vect.size();
            for (int z = 0 ; z < temp ; z++){
                b1.vect.push_back(0);
            }

    }
    else if(vect.size() < b1.vect.size()){
            temp = b1.vect.size() - vect.size();
            for (int z = 0 ; z < temp ; z++){
                vect.push_back(0);
            }

    }
    for(int y = 0 ; y <= vect.size();y++){
            num = vect[y] + b1.vect[y] + c;
            if(num > 10){
                    num -= 10;
                    b2.vect.push_back(num);
                    c = 1;
            }
            else if (num == 10){
                    c = 1;
                    b2.vect.push_back(0);

            }
            else {
                    b2.vect.push_back(num);
                    c = 0;
            }
    }
    if(c != 0){
        b2.vect.push_back(c);
    }
    reverse (b2.vect.begin(),b2.vect.end());
    return b2;



}
