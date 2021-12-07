//
// Created by admin233 on 2021/12/7.
//

#include "Web.h"
#include "Utils.h"
bool Web::CheckNginxConfig(){
    int fd = open(this->NgnixConfig.c_str(),O_RDONLY);
    if (fd == 0){
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
// https://developer.aliyun.com/article/766958
void Web::CheckNginxSSL(){
    auto logger = spdlog::basic_logger_mt("CheckNginxSSL_logger", "logs/basic-log.txt");
    if (!this->CheckNginxConfig()){
        spdlog::critical("NgnixConfig does not exist!");
        logger->critical("NgnixConfig does not exist!");
        return;
    }
    // listen       443 ssl;
    bool sslok = false;
    ifstream in(this->NgnixConfig);
    string line;
    if (in){
        while (getline(in,line)){
            if (Utils::KMPsearch(line,"443 ssl")){
                sslok = true;
                break;
            }
        }
    }
    if (sslok){
        spdlog::info("Nginx SSL is enabled");
        logger->info("Nginx SSL is enabled");
    }
    else{
        spdlog::critical("Nginx SSL is not enabled");
        logger->critical("Nginx SSL is not enabled");
    }
}