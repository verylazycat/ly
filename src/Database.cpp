//
// Created by admin233 on 2021/11/16.
//
#include "Database.h"
//检测mysql是否存在
bool Database::DetectMysql(void){
    auto logger = spdlog::basic_logger_mt("DetectMysql_logger", "logs/basic-log.txt");
    int fd = open(this->MysqlConf,O_RDONLY);
    if (fd == 0){
        spdlog::warn("you are not install Mysql or install error place!");
        logger->warn("you are not install Mysql or install error place!");
        return false;
    }
    close(fd);
    return true;
}