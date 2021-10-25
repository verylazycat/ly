#include "banner.h"
#include "Accounting.h"
#include "Auth.h"
#include "Boot.h"
int main() {
    // Accounting accounting;
    // accounting.BaseInfo();
    // Auth auth;
    // auth.CheckIsOnlyUser();
    // auth.CheckNoPwUser();
    // auth.CheckUmask();
    Boot boot;
    boot.CheckGrubBootLoader();
    return 0;
}
