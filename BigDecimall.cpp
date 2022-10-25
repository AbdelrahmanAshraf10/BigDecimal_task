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
bool BigDecimall:: operator> (BigDecimall b)
{
    if((s == '+')&& (b.s== '+'))
    {
        if(vect.size()==b.vect.size())
        {
            for(int i=1;i <= vect.size();i++)
            {
                if(vect[i]>b.vect[i])
                {
                    return true;
                    break;
                }
                else if(vect[i]<b.vect[i])
                {
                    return false;
                    break;
                }
            }
        }
        else if (vect.size() > b.vect.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if((s =='+') && (b.s=='-'))
    {
        return true;
    }
    else if ((s == '-')&&(b.s == '+'))
    {
        return false ;
    }
    else if((s == '-')&& (b.s == '-'))
    {
            if(vect.size()==b.vect.size())
        {
            for(int i=1;i <= vect.size();i++)
            {
                if(vect[i]<b.vect[i])
                {
                    return true;
                    break;
                }
                else if(vect[i]>b.vect[i])
                {
                    return false;
                    break;
                }
            }
        }
        else if (vect.size() < b.vect.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

bool BigDecimall:: operator == (BigDecimall b)
{
    if ((s == b.s) && (vect.size() == b.vect.size()))
    {
        for(int i=1;i<=vect.size();i++)
        {
            if(vect[i]!=b.vect[i])
            {
                return false;
                break;
            }
            else
            {
                return true;
            }
        }
    }
    else
    {
        return false;
    }
}


ostream& operator << (ostream& out, BigDecimall b)
{
    for(int i=0;i<b.vect.size();i++)
    {
        out<<b.vect[i];
    }
    return out;
}
BigDecimall BigDecimall ::operator-(BigDecimall a1)
{
    BigDecimall a2;
    int temp,num,b = 0,check , counter = 0;

    reverse(vect.begin(),vect.end());
    reverse(a1.vect.begin(),a1.vect.end());

    if(vect.size() > a1.vect.size())
    {
        temp = vect.size() - a1.vect.size();
        for(int i = 0; i < temp; i++)
        {
            a1.vect.push_back(0);
        }
    }
    else if(vect.size() < a1.vect.size())
    {
        temp = a1.vect.size() - vect.size();
        for(int i = 0; i < temp; i++)
        {
            vect.push_back(0);
        }
    }
    for(int i = 0; i < vect.size(); i++)
    {
        if(vect[i] > a1.vect[i])
        {
            check = 1;
            break;
        }
        else if (vect[i] < a1.vect[i])
        {
            check = 2;
            break;
        }
        else if(vect[i] == a1.vect[i])
        {
            counter++;
        }
    }
    if(counter == vect.size())
    {
        cout<<0<<endl;
    }
    if(check == 1)
    {
        for(int i = 0; i < vect.size();i++)
        {
            num = vect[i] - a1.vect[i] - b;
            if(num < 0)
            {
                num += 10;
                b = 1;
                a2.vect.push_back(num);
            }
            else if (num == 0)
            {
                a2.vect.push_back(0);
                b = 0;
            }
            else if(num > 0)
            {
                a2.vect.push_back(num);
                b = 0;
            }


        }
    }
    else if(check == 2)
    {
        for(int i = 0; i < vect.size();i++)       //285
        {                                         //395
            num = vect[i] - a1.vect[i] - b;
            if(num < 0)
            {
                num = abs(num);
                a2.vect.push_back(num);
            }
            else if (num == 0)
            {
                a2.vect.push_back(0);
                b = 0;
            }
            else if(num > 0)
            {
                a2.vect.push_back(num);
                b = 0;
            }
        }
        a2.s = '-';
        cout<<a2.s;


    }
reverse(a2.vect.begin(),a2.vect.end());
return(a2);
}
bool operator<(BigDecimall a1,BigDecimall a2)
{
    if(a1.s =='+' && a2.s == '+')
    {
        if(a1.vect.size() == a2.vect.size())
        {
            for(int i = 0; i < a1.vect.size();i++)
            {
                if(a1.vect[i] > a2.vect[i])
                {
                    return(false);
                    break;
                }
                else{
                    return(true);
                    break;
                }
            }
        }
        else if(a1.vect.size()>a2.vect.size())
        {
            return(false);

        }
        else if(a1.vect.size()<a2.vect.size())
        {
            return(true);

        }
    }
    else if(a1.s == '+' && a2.s == '-')
    {
        return(false);

    }
    else if(a1.s == '-' && a2.s == '+'){

        return(true);
    }
    else if(a1.s == '-' && a2.s =='-')
    {
        if(a1.vect.size() == a2.vect.size())
        {
            for(int i = 0; i < a1.vect.size();i++)
            {
                if(a1.vect[i] > a2.vect[i])
                {
                    return(false);
                }
                else{
                    return(true);
                    break;
                }
            }
        }
        else if(a1.vect.size()>a2.vect.size())
        {
            return(true);
        }
        else if(a1.vect.size()< a2.vect.size())
        {
            return(false);
        }
    }
}
