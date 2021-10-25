//
// Created by admin233 on 2021/10/7.
//

#ifndef LY_AUTH_H
#define LY_AUTH_H
#include <unordered_set>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "Utils.h"

class Auth{
//private:
public:
    void CheckIsOnlyUser();
    void CheckNoPwUser();
    void CheckUmask();
};
#endif //LY_AUTH_H
