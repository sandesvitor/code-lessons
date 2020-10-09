#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int width;

public:
    Rectangle() { length = width = 1; }
    Rectangle(int l, int w);
    int area();
    int perimeter();
    int getLength() { return length; }
    void setLength(int l) { length = l; }
    ~Rectangle();
};

// "::" scope resolution!
Rectangle ::Rectangle(int l, int w)
{
    length = l;
    width = w;
}

int Rectangle ::area()
{
    return length * width;
}

int Rectangle ::perimeter()
{
    return 2 * (length + width);
}

Rectangle ::~Rectangle() {}

int main()
{
    Rectangle r(10, 5);
    cout << r.area();

    printf("\n");

    cout << r.perimeter();

    printf("\n");

    r.setLength(20);
    cout << r.getLength();

    return 0;
}