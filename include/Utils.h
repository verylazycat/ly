//
// Created by admin233 on 2021/9/25.
//
#ifndef LY_UTILS_H
#define LY_UTILS_H
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h> 
#include <unistd.h> 
#include <netdb.h>
#include <net/if.h>  
#include <arpa/inet.h> 
#include <sys/ioctl.h>  
#include <sys/types.h>  
#include <sys/time.h> 
#include <iomanip>
#include <openssl/md5.h>
#include <mysql/mysql.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#define MAXDATABUFF 1024
#define MD5LENTH 16

using namespace std;
class Utils {
public:
    static char *GetNameFromPass(char *ps);
    static char *GetPassFromPass(char  *ps);
    static string CalculateMD5(const string &filePath);
    static string dec2hex(int x);
    static bool KMPsearch(const string &text,const string &pattern);
    static void  executeCMD(const char *cmd,char *res);
    static string get_local_ip(const char *eth_inf);
    static void updatebyip(const char *db_name,string table_name,string column,string value);
};


#endif //LY_UTILS_H
