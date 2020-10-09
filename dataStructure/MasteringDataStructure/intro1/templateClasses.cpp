#include <iostream>
using namespace std;

// T can be int, float, double, ... (generic datatype)
// it's a more generic class!!!
template <class T>
class Arithametic
{
private:
    T a;
    T b;

public:
    Arithametic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithametic<T>::Arithametic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arithametic<T>::add()
{
    T c;
    c = a + b;
    return c;
}

template <class T>
T Arithametic<T>::sub()
{
    T c;
    c = a - b;
    return c;
}

int main()
{
    Arithametic<int> a(10, 5);
    cout << a.add();
    printf("\n");

    Arithametic<float> b(1.2, 5.9);
    cout << b.sub();
    printf("\n");

    return 0;
}
