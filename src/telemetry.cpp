#include <iostream>
#include <functional>
#include <string>
#include <CLI11.hpp>

#include "telemetry.hpp"

int main(int argc, char **argv) 
{
    using std::cout;
    using std::endl;
    CLI::App app{"Telemetry for hardware sensors"};

    std::string syspath="";
    app.add_option("-o", syspath, "System path");

    auto path = syspath;

    try
    {
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        return app.exit(e);    
    }

    if(!syspath.empty())
    {
        cout << "Syspath: " << syspath << "\n";
        //now that the syspath has been provided, we need to get the path through findHwmonFromOFPath(path)
        //for this we need to include phosphor-hwmon
        path = sysfs::findHwmonFromOFPath(path);
        cout << "path: " << path << "\n";
    }
    std::string s1 = "/sys/devices/platform/ahb/ahb:apb/ahb:apb:bus@1e78a000/1e78a300.i2c-bus/i2c-7/7-004d";
    std::string s2 = "/ahb/apb/bus@1e78a000/i2c-bus@300/lm75@4d";
    cout << "s1 + s2 = " << s1 << s2 << "\n";
    cout  << "generated hash = " << std::hash<std::string>{}(s1 + s2) << "\n";

    std::string expected_hash = "1041123473";

    cout << "expected hash = " << expected_hash << "\n";

    return 0;
}
