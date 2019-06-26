#include <iostream>

#include "expressions.h"
#include "vector.h"

using namespace std;

int main()
{
    Vector a = {1.0, 2.0, 3.0};
    Vector b = {10.0, 20.0, 30.0};

    Vector c(a.size());
    c = a + b;

    cout << c << endl;
    return 0;
}
