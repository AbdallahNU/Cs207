#include <iostream>

using namespace std;
class Rectangle
{
    private:
        int width;
        int length;

    public:
        int getArea(void)
        {
            return width*length;
        }
        void setWidth(unsigned int x)
        {
            width = x;
        }
        void setLength(unsigned int x)
        {
            length = x;
        }

};
void bla()
{
   int *a;
    a = new int;
    cout << *a; 
}
int main(void)
{
    // Rectangle a;
    // a.setLength(2);
    // a.setWidth(-5);
    // cout << a.getArea() << endl;

    bla();

    return 0;
}


