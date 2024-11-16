#include <iostream>
#include "cpr/api.h"
#include "cpr/auth.h"
#include "cpr/cprtypes.h"
#include "cpr/parameters.h"

int main()
{
    cpr::Response r = cpr::Get(cpr::Url{"https://andelenergi.dk/?obexport_format=csv&obexport_start=2024-10-18&obexport_end=2024-10-19&obexport_region=east&obexport_tax=0&obexport_product_id=1%231%23TIMEENERGI"}
                      //cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
                      /*cpr::Parameters{{"anon", "true"}, {"key", "value"}}*/);
    r.status_code;
    r.header["content-type"];
    std::cout << r.text;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
