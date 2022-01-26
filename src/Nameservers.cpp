//
// Created by admin233 on 2021/11/21.
//

#include "Nameservers.h"
bool Nameservers::CheckConfigFile(void){
    int fd = open(this->resolvpath.c_str(),O_RDONLY);
    if (fd == 0){
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
//nameserver 127.0.0.53
void Nameservers::CheckDNS(void){
    auto logger = spdlog::basic_logger_mt("CheckDNS_logger", "logs/basic-log.txt");
    if (!this->CheckConfigFile()){
        spdlog::critical("resolv.conf does not exist!");
        logger->critical("resolv.conf does not exist!");
        return;
    }
    ifstream in(this->resolvpath);
    string line;
    if (in){
        while (getline(in,line)){
            if (Utils::KMPsearch(line,"nameserver 127.0.0.53")){
                spdlog::info("Nameserver is the default");
                logger->info("Nameserver is the default");
                Utils::updatebyip("LY-core","Nameservers","DNSdefault",1);
                return;
            }
        }
    }
    spdlog::critical("Nameserver is not the default");
    logger->critical("Nameserver is not the default");
    Utils::updatebyip("LY-core","Nameservers","DNSdefault",0);
    return;
}