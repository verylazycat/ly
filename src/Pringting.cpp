//
// Created by admin233 on 2021/11/17.
//
#include "Printing.h"
//https://www.jianshu.com/p/0868dd2d5418
void Printing::CheckCUPSPermissions(void){
    auto logger = spdlog::basic_logger_mt("CheckCUPSPermissions_logger", "logs/basic-log.txt");
    // -rwxr-xr-x : cupsfilter
    const char *cmd = "ls -la /sbin/cupsfilter | awk '{print $1}'";
    char res[1024] = "";
    Utils::executeCMD(cmd,res);
    if (Utils::KMPsearch(res,"-rwxr-xr-x")){
        spdlog::info("CUPS permission security");
        logger->info("CUPS permission security");
        Utils::updatebyip("LY-core","Printing","CUPSpermissionsecurity",1);
        return;
    }
    spdlog::critical("CUPS permission not security");
    logger->critical("CUPS permission not security");
    Utils::updatebyip("LY-core","Printing","CUPSpermissionsecurity",0);
    return;
}
// Listen localhost:631
// WebInterface No
void Printing::CheckCUPSRemoteAccess(){
    auto logger = spdlog::basic_logger_mt("CheckCUPSRemoteAccess_logger", "logs/basic-log.txt");
    bool listen = false;
    bool webinterface = false;
    ifstream in(this->CUPSConfig);
    string line;
    if (in){
        while (getline(in,line)){
            if (Utils::KMPsearch(line,"Listen localhost:631")){
                listen = !listen;
                continue;
            }
            else if(Utils::KMPsearch(line,"WebInterface No")){
                webinterface = !webinterface;
                continue;
            }
            if (listen && webinterface){
                spdlog::info("Remote has been disabled.");
                logger->info("Remote has been disabled.");
                Utils::updatebyip("LY-core","Printing","Remote",0);
                return;
            }
        }
    }
    if (listen){
        spdlog::critical("Unsafe configuration:{WebInterface No}");
        logger->critical("Unsafe configuration:{WebInterface No}");
        Utils::updatebyip("LY-core","Printing","safeconfiguration",0);
        Utils::updatebyip("LY-core","Printing","WebInterface","NO");
        return;
    }
    else if (webinterface){
        spdlog::critical("Unsafe configuration:{Listen localhost:631}");
        logger->critical("Unsafe configuration:{Listen localhost:631}");
        Utils::updatebyip("LY-core","Printing","safeconfiguration",0);
        Utils::updatebyip("LY-core","Printing","WebInterface","localhost:631");
        return;
    }
    else{
        spdlog::critical("Remote accessibility");
        logger->critical("Remote accessibility");
        Utils::updatebyip("LY-core","Printing","Remote",1);
        return;
    }
}