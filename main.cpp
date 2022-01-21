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
#include "Squid.h"
#include "Framework.h"
#include "Utils.h"
#include "Firewall.h"
#include "Hardening.h"
#include <openssl/md5.h>
#include <iostream>
#include <fstream> 
#include <iomanip>
#include <string>
#include <gflags/gflags.h>
using namespace std;
#define MAXDATABUFF 1024
#define MD5LENTH 16
DEFINE_bool(default_scan, true, "default scan,exclude virus scan");
DEFINE_bool(ac,false,"accounting scan");
DEFINE_bool(au,false,"auth scan");
DEFINE_bool(cr,false,"crypto scan");
DEFINE_bool(da,false,"database scan");
DEFINE_bool(pr,false,"printing scan");
static std::string g_version;
static std::string g_help;
//========== version define ==========
std::string& getVersion() {
    g_version = "1.0.0";
    return g_version;
    }
//========== help info define ==========
std::string& getHelp() {
    g_help = "help info";
    return g_help;
    }
int main(int argc ,char **argv) {
    //========== init gflags ==========

    google::SetVersionString(getVersion());
    google::SetUsageMessage(getHelp());
    google::ParseCommandLineFlags(&argc, &argv, true);
    
    //========== init core function object ==========
    
    Accounting accounting;
    Auth auth;
    Boot boot;
    Crypto crypto;
    Database database;
    Printing printing;
    Logging logging;
    Nameservers nameservers;
    SSH ssh;
    Tools tools;
    Processes processes;
    Web web;
    Malware malware;// more time to scan
    Kernel kernel;
    NetWorking netWorking;
    FileIntegrity fileintegrity;    
    Framework framework;
    Firewall firewall;
    Hardening hardening;
    Squid squid;
    //========== gflags setting ==========
    ///========== default init ==========
    if (FLAGS_ac || FLAGS_au || FLAGS_cr || FLAGS_da ||FLAGS_pr){
        FLAGS_default_scan = !FLAGS_default_scan;
    }
    ///========== default scan ==========
    if (FLAGS_default_scan){
        accounting.BaseInfo();
        auth.CheckIsOnlyUser();
        auth.CheckNoPwUser();
        auth.CheckUmask();
        boot.CheckAuthBoot();
        boot.CheckCron();
        boot.CheckGrubBootLoader();
        crypto.CheckCerts();
        database.CheckDangerousCMD();
        database.CheckIntranetAccess();
        database.CheckNullPass();
        database.CheckRedisPass();
        printing.CheckCUPSPermissions();
        printing.CheckCUPSRemoteAccess();
        logging.AuditConfiguration();
        logging.AuditLog();
        nameservers.CheckDNS();
        ssh.AuditSSHConfig();
        // tools.CheckFailBanConfig();
        processes.RetrievingZombieProcesses();
        web.CheckNginxLog();
        web.CheckNginxSSL();
        kernel.CheckCoreDumpOK();
        kernel.CheckCPUINIFO();
        kernel.CheckPAE();
        kernel.CheckSYSCTL();
        kernel.CheckSysCtlValue();
        netWorking.arp();
        netWorking.HostsParsing();
        netWorking.NicStatus();
        netWorking.ss();
        fileintegrity.CheckAIDE();
        fileintegrity.CheckNecessaryBlock();
        fileintegrity.CheckSwap();
        fileintegrity.CheckTmp();
        fileintegrity.TmpStickybit();
        framework.apparmor_status();
        hardening.CheckCMAKE();
        hardening.CheckGCC();
        hardening.CheckGPP();
        squid.CheckSquidStatus();
    }
    ///========== user setting  ==========
    if (FLAGS_ac){
        accounting.BaseInfo();
    }
    if (FLAGS_au){
        auth.CheckIsOnlyUser();
        auth.CheckNoPwUser();
        auth.CheckUmask();
    }
    if (FLAGS_cr){
        crypto.CheckCerts();
    }
    if (FLAGS_da){
        database.CheckDangerousCMD();
        database.CheckIntranetAccess();
        database.CheckNullPass();
        database.CheckRedisPass();
    }
    if (FLAGS_pr){
        printing.CheckCUPSPermissions();
        printing.CheckCUPSRemoteAccess();
    }
    
    return 0;
}
