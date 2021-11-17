//
// Created by admin233 on 2021/11/16.
//

#ifndef LY_DATABASE_H
#define LY_DATABASE_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include "Utils.h"
#include <mysql/mysql.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
using namespace std;
class Database {
private:
    const char *MysqlConf = "/etc/mysql";
    const char *RedisConf = "/etc/redis/redis.conf";
public:
    bool DetectMysql(void);
    void CheckNullPass(void);
    bool DetectRedis(void);
    //TODO:https://blog.csdn.net/lihuaichen/article/details/80582820
    void CheckDangerousCMD(void);
    void CheckRedisPass(void);
    void CheckIntranetAccess(void);
};


#endif //LY_DATABASE_H
