#include <stdio.h>

// C++ Class:
class Rectangle
{
private:
    int length;
    int width;

public:
    // CONSTRUCTOR
    Rectangle(int l, int w)
    {
        length = l;
        width = w;
    }

    int getLengh()
    {
        return length;
    }

    int getWidth()
    {
        return width;
    }

    int area()
    {
        return length * width;
    }

    void changeDimensions(int newLength, int newWidth)
    {
        length = newLength;
        width = newWidth;
    }
};

int main()
{
    Rectangle rect(10, 5);

    printf("Rectangle dimensios:\nLength = %d\nWidth = %d\n", rect.getLengh(), rect.getWidth());

    int rectArea = rect.area();
    printf("Rectangle Area = %d\n", rectArea);

    rect.changeDimensions(20, 50);
    printf("Rectangle NEW dimensios:\nLength = %d\nWidth = %d\n", rect.getLengh(), rect.getWidth());
    return 0;
}