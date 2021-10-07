#include "banner.h"
#include "Accounting.h"
#include "Auth.h"
int main() {
    Accounting accounting;
    accounting.BaseInfo();
    accounting.CheckUmask();
    Auth auth;
    auth.CheckIsOnlyUser();
    auth.CheckNoPwUser();
    return 0;
}
