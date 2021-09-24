#include <iostream>
#include "banner.h"
#include "Accounting.h"
int main() {
    Accounting accounting;
    accounting.BaseInfo();
    accounting.CheckUmask();
    return 0;
}
