#include <iostream>
using namespace std;

//void interschimbare(int z, int w)
//{
//    int aux = z;
//    z = w;
//    w = aux;
//}

void interschimbare(int* z, int* w)
{
    if (z == nullptr || w == nullptr)
    {
        return;
    }

    int aux = *z;
    *z = *w;
    *w = aux;
}

void interschimbare(int& z, int& w)
{
    int aux = z;
    z = w;
    w = aux;
}

int main()
{
    /*
    * pointeri (provin din C)
    * referinte (specifice C++)
    */

    int x = 5;
    int* ptr = &x;

    int y = *ptr;

    cout << y << '\n';
    cout << *ptr << '\n';

    x = 100; // *ptr = 100;

    cout << y << '\n';
    cout << *ptr << '\n';

    y = 25;
    *ptr = 0; // x = 0;

    cout << y << '\n'; // 25
    cout << *ptr << '\n'; // 0
    cout << x << '\n'; // 0

    cout << "============================\n";

    int a = 3;
    int b = 9;

    cout << a << '\n';
    cout << b << '\n';

    //interschimbare(a, b); - apel prin valoare

    interschimbare(&a, &b);

    cout << a << '\n';
    cout << b << '\n';

    int& ref = a;

    ref = 5;
    cout << a << '\n';
    a = 800;
    cout << ref << '\n';

    cout << &a << '\n';
    cout << &ref << '\n';

    interschimbare(a, b);

    cout << a << '\n';
    cout << b << '\n';

    return 0;
}