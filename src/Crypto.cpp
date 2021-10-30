//
// Created by admin233 on 2021/10/28.
//

// https://blog.csdn.net/think_A_lot/article/details/86326604
// https://blog.csdn.net/a137748099/article/details/120248098
#include "Crypto.h"
void Crypto::CheckCerts(){
    int overdue = 0;
    auto logger = spdlog::basic_logger_mt("CheckCerts_logger", "logs/basic-log.txt");
    //get year cmd
    const char *cmd = "openssl x509 -in /etc/ssl/certs/02265526.0 -noout -enddate | awk '{print $4}'";
    char year[1024] = "";
    Utils::executeCMD(cmd,year);
    time_t nowtime;
	struct tm* p;
	time(&nowtime);
	p = localtime(&nowtime);
    if (atoi(year) < (p->tm_year + 1900)){
        logger->critical("Certificate expired");
        spdlog::critical("Certificate expired");
        overdue++;
    }
    if (overdue){
        logger->critical("total of {} certificates have expired",overdue);
        spdlog::critical("total of {} certificates have expired",overdue);
    }
    else{
        logger->info("All Certificate security");
        spdlog::info("All Certificate security");
    }
    //todo:文件遍历。。。
}