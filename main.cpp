#include <iostream>
#include <string>
#include "Core/logger.cpp"
#include "Math/complexe_number.cpp"
using namespace core;
using namespace math;

int main()
{
    logger::set_log_type(log_type::console);
    logger::log("Start of the execution");

    complexe_number a(.3,-.45);
    complexe_number b(.34,.005);
    complexe_number c = a + b;
    c.set_real_part(1);

    logger::log(c.to_string());
    return 0;
}