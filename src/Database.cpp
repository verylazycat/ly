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
//检测是否安装redis
bool Database::DetectRedis(void){
    int fd = open(this->RedisConf,O_RDONLY);
    if (fd == 0){
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
//高危指令限制检测:禁用远程修改 DB 文件地址
void Database::CheckDangerousCMD(void){
    auto logger = spdlog::basic_logger_mt("CheckDangerousCMD_logger", "logs/basic-log.txt");
    bool FLUSHALL = false;
    bool CONFIG = false;
    bool EVAL = false;
    if (!this->DetectRedis()){
        spdlog::info("You are Not installed Redis");
        logger->info("You are Not installed Redis");
        return;
    }
    ifstream in(this->RedisConf);
    string line;
    if (in){
        while (getline(in,line)){
            if (Utils::KMPsearch(line,"rename-command FLUSHALL \"\"")){
                FLUSHALL = !FLUSHALL;
                continue;
            }
            else if (Utils::KMPsearch(line,"rename-command CONFIG \"\"")){
                CONFIG = !CONFIG;
                continue;
            }
            else if (Utils::KMPsearch(line,"rename-command EVAL \"\"")){
                EVAL = !EVAL;
                continue;
            }
            continue;
        }
    }
    if (FLUSHALL){
        spdlog::info("Redis-FLUSHALL is safe");
        logger->info("Redis-FLUSHALL is safe");
    }
    else{
        spdlog::critical("Redis-FLUSHALL is not safe");
        logger->critical("Redis-FLUSHALL is not safe");
    }
    if (CONFIG){
        spdlog::info("Redis-CONFIG is safe");
        logger->info("Redis-CONFIG is safe");
    }
    else{
        spdlog::critical("Redis-CONFIG is not safe");
        logger->critical("Redis-CONFIG is not safe");
    }
    if (EVAL){
        spdlog::info("Redis-EVAL is safe");
        logger->info("Redis-EVAL is safe");
    }
    else{
        spdlog::critical("Redis-EVAL is not safe");
        logger->critical("Redis-EVAL is not safe");
    }
    return;
}
void Database::CheckRedisPass(){
    auto logger = spdlog::basic_logger_mt("CheckRedisPass_logger", "logs/basic-log.txt");
    if (!this->DetectRedis()){
        spdlog::info("You are Not installed Redis");
        logger->info("You are Not installed Redis");
        return;
    }
    ifstream in(this->RedisConf);
    string line;
    if(in){
        while (getline(in,line)){
            if(Utils::KMPsearch(line,"# requirepass")){
                spdlog::critical("Redis does not set a password");
                logger->critical("Redis does not set a password");
                return;
            }
        }
    }
    spdlog::info("Redis has set the password");
    logger->info("Redis has set the password");
    return;
}
void Database::CheckIntranetAccess(void){
    auto logger = spdlog::basic_logger_mt("CheckIntranetAccess_logger", "logs/basic-log.txt");
    if (!this->DetectRedis()){
        spdlog::info("You are Not installed Redis");
        logger->info("You are Not installed Redis");
        return;
    }
    ifstream in(this->RedisConf);
    string line;
    if(in){
        while (getline(in,line)){
            if(Utils::KMPsearch(line,"# bind 127.0.0.1")){
                spdlog::critical("The extranet can access Redis");
                logger->critical("The extranet can access Redis");
                return;
            }
        }
    }
    spdlog::info("The extranet can not access Redis");
    logger->info("The extranet can not access Redis");
    return;
}