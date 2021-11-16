//
// Created by admin233 on 2021/11/16.
//
#include "Database.h"
//检测mysql是否存在
bool Database::DetectMysql(void){
    int fd = open(this->MysqlConf,O_RDONLY);
    if (fd == 0){
        close(fd);
        return false;
    }
    close(fd);
    return true;
}

//检测空密码
//sudo apt-get install libmysqlclient-dev
void Database::CheckNullPass(void){
    auto logger = spdlog::basic_logger_mt("CheckNullPass_logger", "logs/basic-log.txt");
    const char *db_host = "locakhost";
    const char *db_user = "root";
    const char *db_pass = "";
    const char *db_name = "";
    const int db_port = 3306;
    MYSQL *mysql = mysql_init(NULL);
    if (mysql == NULL){
        spdlog::critical("mysql error:{}",mysql_error(mysql));
        logger->critical("mysql error:{}",mysql_error(mysql));
        return;
    }
    mysql = mysql_real_connect(mysql,db_host,db_user,db_pass,db_name,db_port,NULL,0);
    if (mysql){
        spdlog::critical("The mysql password empty");
        logger->critical("The mysql password empty");
        mysql_close(mysql);
    }
    spdlog::info("The mysql password not empty");
    logger->info("The mysql password not empty");
    return;
}