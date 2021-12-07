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
void Web::CheckNginxLog(){
    auto logger = spdlog::basic_logger_mt("CheckNginxLog_logger", "logs/basic-log.txt");
    if (!this->CheckNginxConfig()){
        spdlog::critical("NgnixConfig does not exist!");
        logger->critical("NgnixConfig does not exist!");
        return;
    }
    bool access_log = false;
    bool error_log = false;
    ifstream in(this->NgnixConfig);
    string line;
    if (in){
        while (getline(in,line)){
            if (!access_log && Utils::KMPsearch(line,"access_log")){
                access_log = true;
                continue;
            }
            if (!error_log && Utils::KMPsearch(line,"error_log")){
                error_log = true;
                continue;
            }
            if (access_log && error_log){
                break;
            }
        }
    }
    if (access_log){
        spdlog::info("Ngnix Access_log is ok");
        logger->info("Ngnix Access_log is ok");
    }
    else{
        spdlog::critical("Ngnix Access_log is not ok");
        logger->critical("Ngnix Access_log is not ok");
    }
    if (error_log){
        spdlog::info("Ngnix Error_log is ok");
        logger->info("Ngnix Error_log is ok");
    }
    else{
        spdlog::critical("Ngnix Error_log is not ok");
        logger->critical("Ngnix Error_log is not ok");
    }
}