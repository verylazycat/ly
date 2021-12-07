#include "banner.h"
#include "Accounting.h"
#include "Auth.h"
#include "Boot.h"
#include "Crypto.h"
#include "Database.h"
#include "Printing.h"
#include "Logging.h"
#include "Nameservers.h"
#include "SSH.h"
#include "Tools.h"
#include "Processes.h"
#include "Web.h"
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
    Crypto crypto;
    accounting.BaseInfo();
    
    auth.CheckIsOnlyUser();
    auth.CheckNoPwUser();
    auth.CheckUmask();
    
    boot.CheckGrubBootLoader();
    boot.CheckAuthBoot();
    boot.CheckCron();

    crypto.CheckCerts();
    Database database;
    database.CheckNullPass();
    database.CheckDangerousCMD();
    database.CheckRedisPass();
    database.CheckIntranetAccess();

    Printing printing;
    printing.CheckCUPSPermissions();
    printing.CheckCUPSRemoteAccess();

    Logging logging;
    logging.AuditConfiguration();

    Nameservers nameservers;
    nameservers.CheckDNS();

    SSH ssh;
    ssh.AuditSSHConfig();

    Tools tools;
    tools.CheckFailBanConfig();

    Processes processes;
    processes.RetrievingZombieProcesses();

    Web web;
    web.CheckNginxSSL();
    web.CheckNginxLog();
    return 0;
}
