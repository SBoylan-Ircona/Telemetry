#include <iostream>
#include <functional>
#include <string>

#include "telemetry.h"


using namespace std;

int main() 
{
    std::string s1 = "/sys/devices/platform/ahb/ahb:apb/ahb:apb:bus@1e78a000/1e78a300.i2c-bus/i2c-7/7-004d";
    std::string s2 = "/ahb/apb/bus@1e78a000/i2c-bus@300/lm75@4d";
    std::cout << "s1 + s2 = " << s1 << s2 << "\n";
    std::cout  << "generated hash = " << std::hash<std::string>{}(s1 + s2) << "\n";

    std::string expected_hash = "1041123473";

    std::cout << "expected hash = " << expected_hash << "\n";

    return 0;
}