#include <iostream>

#include "petl/expressions.h"
#include "MyVec.h"

using namespace std;

int main()
{
    MyVec a = {1.0, 2.0, 3.0};
    MyVec b = {10.0, 20.0, 30.0};

    MyVec c(a.size());
    c = a + b;

    cout << c << endl;
    return 0;
}
