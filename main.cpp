#include <iostream>
#include "banner.h"
#include "Accounting.h"
#include "Utils.h"
int main() {
    Accounting accounting;
//    accounting.BaseInfo();
//    accounting.CheckUmask();
    accounting.CheckIsOnlyUser();
    return 0;
}
