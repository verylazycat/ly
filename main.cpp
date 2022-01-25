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
DEFINE_bool(lo,false,"logging scan");
DEFINE_bool(na,false,"nameservers scan");
DEFINE_bool(ss,false,"ssh scan");
DEFINE_bool(to,false,"tools scan");
DEFINE_bool(pro,false,"processes scan");
DEFINE_bool(we,false,"web scan");
DEFINE_bool(ma,false,"malware scan");
DEFINE_bool(ke,false,"kernel scan");
DEFINE_bool(ne,false,"netWorking scan");
DEFINE_bool(fi,false,"fileintegrity scan");
DEFINE_bool(fr,false,"framework scan");
DEFINE_bool(fir,false,"firewall scan");
DEFINE_bool(ha,false,"hardening scan");
DEFINE_bool(sq,false,"squid scan");
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
    spdlog::info("======== init start ========");
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
    if (FLAGS_ac || FLAGS_au || FLAGS_cr || FLAGS_da ||FLAGS_pr
            || FLAGS_lo || FLAGS_na || FLAGS_ss || FLAGS_to || FLAGS_pro
            || FLAGS_we || FLAGS_ma || FLAGS_ke || FLAGS_ne || FLAGS_fi
            || FLAGS_fr || FLAGS_fir || FLAGS_ha || FLAGS_sq)
            {
                FLAGS_default_scan = !FLAGS_default_scan;
            }
    spdlog::info("======== init end ========");
    ///========== default scan ==========
    if (FLAGS_default_scan){
        spdlog::info("======== default scan start ========");
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
        firewall.GetIptabelse();
        hardening.CheckCMAKE();
        hardening.CheckGCC();
        hardening.CheckGPP();
        squid.CheckSquidStatus();
        spdlog::info("======== default scan end ========");
    }
    ///========== user setting  ==========
    if (FLAGS_ac){
        spdlog::info("======== accounting scan start ========");
        accounting.BaseInfo();
        spdlog::info("======== accounting scan end ========");
    }
    if (FLAGS_au){
        spdlog::info("======== auth scan start ========");
        auth.CheckIsOnlyUser();
        auth.CheckNoPwUser();
        auth.CheckUmask();
        spdlog::info("======== auth scan end ========");
    }
    if (FLAGS_cr){
        spdlog::info("======== crypto scan start ========");
        crypto.CheckCerts();
        spdlog::info("======== crypto scan end ========");
    }
    if (FLAGS_da){
        spdlog::info("======== database scan start ========");
        database.CheckDangerousCMD();
        database.CheckIntranetAccess();
        database.CheckNullPass();
        database.CheckRedisPass();
        spdlog::info("======== database scan end ========");
    }
    if (FLAGS_pr){
        spdlog::info("======== printing scan start ========");
        printing.CheckCUPSPermissions();
        printing.CheckCUPSRemoteAccess();
        spdlog::info("======== printing scan end ========");
    }
    if (FLAGS_lo){
        spdlog::info("======== logging scan start ========");
        logging.AuditConfiguration();
        logging.AuditLog();
        spdlog::info("======== logging scan end ========");
    }
    if (FLAGS_na){
        spdlog::info("======== nameservers scan start ========");
        nameservers.CheckDNS();
        spdlog::info("======== nameservers scan end ========");
    }
    if (FLAGS_ss){
        spdlog::info("======== ssh scan start ========");
        ssh.AuditSSHConfig();
        spdlog::info("======== ssh scan end ========");
    }
    if (FLAGS_to){
        spdlog::info("======== tools scan start ========");
        // tools.CheckFailBanConfig();
        spdlog::info("======== tools scan end ========");
    }
    if (FLAGS_pro){
        spdlog::info("======== processes scan start ========");
        processes.RetrievingZombieProcesses();
        spdlog::info("======== processes scan end ========");
    }
    if (FLAGS_we){
        spdlog::info("======== web scan start ========");
        web.CheckNginxLog();
        web.CheckNginxSSL(); 
        spdlog::info("======== web scan end ========");
    }   
    if (FLAGS_ma){
        spdlog::info("======== malware scan start ========");
        malware.BinScan();
        malware.FullScan();
        spdlog::info("======== malware scan end ========");
    }
    if (FLAGS_ke){
        spdlog::info("======== kernel scan start ========");
        kernel.CheckCoreDumpOK();
        kernel.CheckCPUINIFO();
        kernel.CheckPAE();
        kernel.CheckSYSCTL();
        kernel.CheckSysCtlValue(); 
        spdlog::info("======== kernel scan end ========");  
    }
    if (FLAGS_ne){
        spdlog::info("======== netWorking scan start ========");
        netWorking.arp();
        netWorking.HostsParsing();
        netWorking.NicStatus();
        netWorking.ss();
        spdlog::info("======== netWorking scan end ========"); 
    }
    if (FLAGS_fi){
        spdlog::info("======== fileintegrity scan start ========");
        fileintegrity.CheckAIDE();
        fileintegrity.CheckNecessaryBlock();
        fileintegrity.CheckSwap();
        fileintegrity.CheckTmp();
        fileintegrity.TmpStickybit();
        spdlog::info("======== fileintegrity scan end ========"); 
    }
    if (FLAGS_fr){
        spdlog::info("======== framework scan start ========");
        framework.apparmor_status(); 
        spdlog::info("======== framework scan end ========"); 
    }
    if (FLAGS_fir){
        spdlog::info("======== firewall scan start ========");
        firewall.GetIptabelse();
        spdlog::info("======== firewall scan end ========"); 
    }
    if (FLAGS_ha){
        spdlog::info("======== hardening scan start ========");
        hardening.CheckCMAKE();
        hardening.CheckGCC();
        hardening.CheckGPP();
        spdlog::info("======== hardening scan end ========"); 
    }
    if (FLAGS_sq){
        spdlog::info("======== squid scan start ========");
        squid.CheckSquidStatus();
        spdlog::info("======== squid scan end ========"); 
    }
    return 0;
}