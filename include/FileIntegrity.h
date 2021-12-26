//
// Created by admin233 on 2021/12/22.
//

#ifndef LY_FILEINTEGRITY_H
#define LY_FILEINTEGRITY_H
#include "Utils.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
using namespace std;
class FileIntegrity {
private:
    string fstab = "/etc/fstab";
    string aideconfig = "/etc/aide/aide.conf";
public:
    void CheckNecessaryBlock(void);
    void CheckSwap(void);
    void CheckTmp(void);
    // sudo apt-get install aide
    bool CheckAIDEConfFile(void);
    void CheckAIDE(void);
    void TmpStickybit(void);
};


#endif //LY_FILEINTEGRITY_H
