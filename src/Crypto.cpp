//
// Created by admin233 on 2021/10/28.
//

// https://blog.csdn.net/think_A_lot/article/details/86326604
// https://blog.csdn.net/a137748099/article/details/120248098
#include "Crypto.h"
void Crypto::CheckCerts(){
    auto logger = spdlog::basic_logger_mt("CheckCerts_logger", "logs/basic-log.txt");
    //get year cmd
    const char *cmd = "openssl x509 -in /etc/ssl/certs/02265526.0 -noout -enddate | awk '{print $4}'";
    char year[1024];
    Utils::executeCMD(cmd,year);
    cout<<year;
    spdlog::info(year);
    logger->info(year);
    //todo: year 修正，过期判断，文件遍历。。。
}