#include <iostream>
#include <string>
using namespace std;

enum class OrderBookType{};
enum class Colors{blue, green, brown, red};

int main() {
    unsigned short i = 65538;
    unsigned long j = 65537;

    cout << "size of unsigned short " << sizeof(unsigned short) << endl;
    cout << "i contains " << i << endl;
    cout << "size of unsigned long  " << sizeof(unsigned long) << endl;
    cout << "j contains " << j << endl;

    string s = "hello world";

    float f = 1.5f; // 1.5 is a double, not a float
    double d = 1.5;

    return 0;
}
