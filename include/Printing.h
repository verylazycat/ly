//
// Created by admin233 on 2021/11/17.
//

#ifndef LY_PRINTING_H
#define LY_PRINTING_H
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "Utils.h"
using namespace std;
class Printing {
private:
    string CUPSConfig = "/etc/cups/cupsd.conf";
public:
    void CheckCUPSPermissions(void);
    void CheckCUPSRemoteAccess(void);
};


#endif //LY_PRINTING_H
