//
// Created by admin233 on 2021/9/19.
//

#ifndef LY_ACCOUNTING_H
#define LY_ACCOUNTING_H

#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

class Accounting {
private:
    struct utsname sysuname;
    struct sysinfo info;
public:
    Accounting();
    void BaseInfo();
    void CheckUmask();
};

#endif //LY_ACCOUNTING_H
