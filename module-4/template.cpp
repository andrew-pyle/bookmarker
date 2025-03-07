#include <chrono>
#include <iomanip>
#include <string>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

// ==== DO NOT EDIT BELOW ====================

string now()
{
    ostringstream out;
    const auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    const auto now_local = std::localtime(&now);
    out << std::put_time(now_local, "%FT%T");
    return out.str();
}

// ==== DO NOT EDIT ABOVE=====================

int main()
{
}