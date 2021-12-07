//
// Created by admin233 on 2021/12/7.
//
#ifndef LY_WEB_H
#define LY_WEB_H
#include <string>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

using namespace std;
class Web {
private:
    string NgnixConfig = "/etc/nginx/nginx.conf";
public:
    bool CheckNginxConfig(void);
    void CheckNginxSSL(void);
};


#endif //LY_WEB_H
