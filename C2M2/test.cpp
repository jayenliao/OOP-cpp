#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "Vec3D.h"

using namespace std;

int main() {

    Vec3D vec1;
    vec1.x = 10;
    vec1.y = 12;
    vec1.z = 25;

    int len = vec1.getLength();
    cout << len << endl;

    return 0;
};
