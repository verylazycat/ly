//
// Created by admin233 on 2021/11/16.
//

#ifndef LY_DATABASE_H
#define LY_DATABASE_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mysql/mysql.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

class Database {
private:
    const char *MysqlConf = "/etc/mysql";
public:
    bool DetectMysql(void);
    void CheckNullPass(void);
    //TODO:https://blog.csdn.net/lihuaichen/article/details/80582820
};


#endif //LY_DATABASE_H
