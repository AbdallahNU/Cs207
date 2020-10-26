#include <iostream>

using namespace std;

struct shape
{
    /* data */
};

class Date
{
    private:
        unsigned int day, month, year;

    public:
        Date(unsigned int d, unsigned int m,unsigned int y)
        {
            day=d;
            month=m;
            year=y;
        }
        void getDate()
        {
          cout << day << "/" << month << "/" << year << endl;  
        }
};

int main(void)
{
    Date a(17,3,2001);

    a.getDate();

    Date *p;

    p = new Date(21,5,2016);

    p->getDate();


    

    return 0;
}