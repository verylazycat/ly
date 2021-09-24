//
// Created by admin233 on 2021/9/19.
//

#ifndef LY_ACCOUNTING_H
#define LY_ACCOUNTING_H

#include <sys/utsname.h>
#include <sys/sysinfo.h>

class Accounting {
private:
    struct utsname sysuname;
    struct sysinfo info;
public:
    Accounting();
    void check();
};

#endif //LY_ACCOUNTING_H
