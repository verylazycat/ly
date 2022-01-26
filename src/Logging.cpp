//
// Created by admin233 on 2021/11/18.
//

#include "Logging.h"
bool Logging::CheckLogConfFile(void){
    int fd = open(this->logconf.c_str(),O_RDONLY);
    if (fd == 0){
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
//审计配置文件
void Logging::AuditConfiguration(void){
    auto logger = spdlog::basic_logger_mt("AuditConfiguration_logger", "logs/basic-log.txt");
    if (!this->CheckLogConfFile()){
        spdlog::critical("rsyslog.Conf does not exist!");
        logger->critical("rsyslog.Conf does not exist!");
        return;
    }
    //------------------514 TCP or UDP---------------
    bool tcp514 = true;
    bool udp514 = true;
    ifstream in(this->logconf);
    string line;
    if (in){
        while (getline(in,line)){
            if (Utils::KMPsearch(line,"#input(type=\"imudp\" port=\"514\")")){
                udp514 = false;
                continue;
            }
            if (Utils::KMPsearch(line,"#input(type=\"imtcp\" port=\"514\")")){
                tcp514 = false;
                continue;
            }
            if (!tcp514 || !!udp514){
                break;
            }
        }
    }
    if (!tcp514 || !udp514){
        spdlog::info("provides UDP/TCP syslog reception");
        logger->info("provides UDP/TCP syslog reception");
        Utils::updatebyip("LY-core","Logging","tcpudpreception",1);
    }
    else{
        spdlog::warn("provides UDP/TCP syslog not reception");
        logger->warn("provides UDP/TCP syslog not reception");
        Utils::updatebyip("LY-core","Logging","tcpudpreception",0);
    }
    return;
}
//审计日志
void Logging::AuditLog(void){
    
}