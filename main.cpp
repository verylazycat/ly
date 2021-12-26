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
#include "Malware.h"
#include "Kernel.h"
#include "Networking.h"
#include "FileIntegrity.h"
#include "Framework.h"
#include "Utils.h"
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

    // Malware malware;
    // malware.UpdateDataBase();
    // malware.BinScan();

    Kernel kernel;
    kernel.CheckPAE();
    kernel.CheckCoreDumpOK();

    NetWorking netWorking;
    netWorking.HostsParsing();
    netWorking.NicStatus();
    netWorking.ss();
    netWorking.arp();

    FileIntegrity fileintegrity;
    fileintegrity.CheckNecessaryBlock();
    fileintegrity.CheckSwap();
    fileintegrity.CheckTmp();
    fileintegrity.CheckAIDE();
    fileintegrity.TmpStickybit();
    
    Framework framework;
    framework.apparmor_status();
    Utils::updatebyip("LY-core","BaseInfo","sysrelease","1234");
    return 0;
}
