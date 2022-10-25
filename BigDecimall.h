#ifndef BIGDECIMALL_H
#define BIGDECIMALL_H


class BigDecimall
{
    public:

        BigDecimall();
        BigDecimall(string );
        BigDecimall(int );
        vector<int> vect;
        char s;
        BigDecimall operator + (BigDecimall);
        bool operator> (BigDecimall b);
        bool operator==(BigDecimall b);
        friend ostream& operator << (ostream& out, BigDecimall b);


    protected:

    private:


};

#endif // BIGDECIMALL_H
