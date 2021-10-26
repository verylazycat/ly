#include "banner.h"
#include "Accounting.h"
#include "Auth.h"
#include "Boot.h"
#include <openssl/md5.h>
#include <iostream>
#include <fstream> 
#include <iomanip>
#include <string>
using namespace std;
#define MAXDATABUFF 1024
#define MD5LENTH 16
int main(int argc ,char **argv) {
    Accounting accounting;
    Auth auth;
    Boot boot;

    accounting.BaseInfo();
    
    auth.CheckIsOnlyUser();
    auth.CheckNoPwUser();
    auth.CheckUmask();
    
    boot.CheckGrubBootLoader();
    
    return 0;
}
