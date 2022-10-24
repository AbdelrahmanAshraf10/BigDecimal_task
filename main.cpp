#include<bits/stdc++.h>

using namespace std;
#include "BigDecimall.h"


int main()
{
    BigDecimall a1("123456789012345678901234567890");
    BigDecimall a2 ("113456789011345678901134567890");
    BigDecimall a3;
    a3 = a2 +a1;
    for (int x = 0 ; x < a3.vect.size(); x++){
        cout << a3.vect[x];
    }
}


