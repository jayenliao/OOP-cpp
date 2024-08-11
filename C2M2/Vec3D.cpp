#include <cmath>
#include "Vec3D.h"

int Vec3D::getLength() {
    return sqrt(x*x + y*y + z*z);
};
