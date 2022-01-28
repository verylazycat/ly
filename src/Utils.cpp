//
// Created by admin233 on 2021/9/25.
//

#include "Utils.h"
char *Utils::GetNameFromPass(char *ps) {
    char *res = (char *)malloc(20);
    for(int i = 0;i < strlen(ps);i++){
        if (ps[i] != ':')
            res[i] = ps[i];
        else{
            res[i] = '\0';
            break;
        }
    }
    return res;
}

char *Utils::GetPassFromPass(char *ps) {
    char  *res = (char *) malloc(2);
    for (int i = 0; i < strlen(ps); ++i) {
        if (ps[i] != ':')
            continue;
        else{
            i++;
            res[0] = ps[i];
            res[1] = '\0';
            break;
        }
    }
    return res;
}

//Calculate MD5
string Utils::CalculateMD5(const string &filePath){
    string res = "";
    ifstream ifile(filePath.c_str(),ios::in|ios::binary);
    unsigned char MD5result[MD5LENTH];
    if (ifile.fail()){
        cout<<"open file failure!so only display string MD5!"<<endl;
        return "";
    } 
    MD5_CTX md5_ctx;    
    MD5_Init(&md5_ctx);
    char DataBuff[MAXDATABUFF];
    while(!ifile.eof())
    {
        ifile.read(DataBuff,MAXDATABUFF);   //读文件
        int length = ifile.gcount();
        if(length)
        {
            MD5_Update(&md5_ctx,DataBuff,length);   //将当前文件块加入并更新MD5
        }
    }
    MD5_Final(MD5result,&md5_ctx);  //获取MD5
    for(int i = 0; i < MD5LENTH; i++){
        res += dec2hex(MD5result[i]);
    }
    // cout<<res;
    return res;
}
// to 16 bit
string Utils::dec2hex(int x){
    stringstream ioss;
    string s_temp;
    ioss<<setiosflags(ios::uppercase)<<hex<<x;
    ioss>>s_temp;
    transform(s_temp.begin(),s_temp.end(),s_temp.begin(),::tolower);
    return s_temp;
}
bool Utils::KMPsearch(const string &text,const string &pattern){
    int tLen = text.size();
	int pLen = pattern.size();
	int i = 0;
	int j = 0;
	while (i < tLen && j < pLen){
        if (text[i] == pattern[j]){
			i++;
			j++;
		}else{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == pLen)
		return true;
	else
		return false;
}

void Utils::executeCMD(const char *cmd,char *res){
    // auto logger = spdlog::basic_logger_mt("UtilsexecuteCMD_logger", "logs/basic-log.txt");
    char buf_ps[10000];   
    char ps[10000]={0};   
    FILE *ptr;   
    strcpy(ps, cmd);   
    if((ptr=popen(ps, "r"))!=NULL){   
        while(fgets(buf_ps, 10000, ptr)!=NULL){   
           strcat(res, buf_ps);   
           if(strlen(res)>10000)   
               break;   
        }   
        pclose(ptr);   
        ptr = NULL;   
    }   
    else{   
        spdlog::critical("popen {} error",ps);
    }
}
string Utils::get_local_ip(const char *eth_inf){
    int sd;
    struct sockaddr_in sin;
    struct ifreq ifr;
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == sd){
        printf("socket error: %s\n", strerror(errno));
        return "";
    }
    strncpy(ifr.ifr_name, eth_inf, IFNAMSIZ);
    ifr.ifr_name[IFNAMSIZ - 1] = 0;
    if (ioctl(sd, SIOCGIFADDR, &ifr) < 0){
        printf("ioctl error: %s\n", strerror(errno));
        close(sd);
        return "";
    }
    // printf("interfac: %s, ip: %s\n", eth_inf, inet_ntoa(((struct sockaddr_in*)&ifr.ifr_addr)->sin_addr)); 
    close(sd);
    string res = inet_ntoa(((struct sockaddr_in*)&ifr.ifr_addr)->sin_addr);
    return res;
}
void Utils::updatebyip(const char *db_name,string table_name,string column,string value){
    // auto logger = spdlog::basic_logger_mt("updatebyip1_logger", "logs/basic-log.txt");
    const char *db_host = "localhost";
    const char *db_user = "admin233";
    const char *db_pass = "admin233";
    const int db_port = 3306;
    // enp3s0f1  wlo1  xdroid0
    string localip = get_local_ip("xdroid0");
    MYSQL *mysql = mysql_init(NULL);
    if (mysql == NULL){
        spdlog::critical("mysql error:{}",mysql_error(mysql));
        // logger->critical("mysql error:{}",mysql_error(mysql));
        mysql_close(mysql);
        return;
    }
    mysql = mysql_real_connect(mysql,db_host,db_user,db_pass,db_name,db_port,NULL,0);
    if (!mysql){
        spdlog::critical("mysql error:{}",mysql_error(mysql));
        // logger->critical("mysql error:{}",mysql_error(mysql));
        mysql_close(mysql);
        return;
    }
    MYSQL_RES *result;
    // select * from BaseInfo where ip = 192.168.xxxx
    string query = "select * from ";
    query += table_name;
    query += " where ip = \"";
    query += localip;
    query += "\"";
    // insert into BaseInfo (ip,column) values ("192.168.xxxx","value")
    string insert = "insert into ";
    insert += table_name;
    insert += " (ip,";
    insert += column;
    insert += ") ";
    insert += "values (\"";
    insert += localip;
    insert += "\",\"";
    insert += value;
    insert += "\")";
    // update BaseInfo set column="xxx" where ip = "192.168.xxxx";
    string update = "update ";
    update += table_name;
    update += " set ";
    update += column;
    update += "=\"";
    update +=value;
    update += "\" where ip = \"";
    update += localip;
    update+="\"";  
    if (!mysql_query(mysql,query.c_str())){
        result = mysql_store_result(mysql);
        // result->row_count
        if (!result->row_count){
            //null then insert...
            if (mysql_query(mysql,insert.c_str())){
                //error
                spdlog::critical("mysql error:{}",mysql_error(mysql));
                // logger->critical("mysql error:{}",mysql_error(mysql));
                mysql_free_result(result);
                mysql_close(mysql);
                return;
            }
            mysql_free_result(result);
            mysql_close(mysql);
            return;
        }
        else{
             // not null then update...
            if (mysql_query(mysql,update.c_str())){
                spdlog::critical("mysql error:{}",mysql_error(mysql));
                // logger->critical("mysql error:{}",mysql_error(mysql));
                mysql_free_result(result);
                mysql_close(mysql);
                return;
            }
            mysql_free_result(result);
            mysql_close(mysql);
            return;
        }
    }
}
void Utils::updatebyip(const char *db_name,string table_name,string column,int value){
    // auto logger = spdlog::basic_logger_mt("updatebyip2_logger", "logs/basic-log.txt");
    const char *db_host = "localhost";
    const char *db_user = "admin233";
    const char *db_pass = "admin233";
    const int db_port = 3306;
    // enp3s0f1  wlo1 xdroid0
    string localip = get_local_ip("xdroid0");
    MYSQL *mysql = mysql_init(NULL);
    if (mysql == NULL){
        spdlog::critical("mysql error:{}",mysql_error(mysql));
        // logger->critical("mysql error:{}",mysql_error(mysql));
        mysql_close(mysql);
        return;
    }
    mysql = mysql_real_connect(mysql,db_host,db_user,db_pass,db_name,db_port,NULL,0);
    if (!mysql){
        spdlog::critical("mysql error:{}",mysql_error(mysql));
        // logger->critical("mysql error:{}",mysql_error(mysql));
        mysql_close(mysql);
        return;
    }
    MYSQL_RES *result;
    // select * from BaseInfo where ip = "192.168.xxxx"
    string query = "select * from ";
    query += table_name;
    query += " where ip = \"";
    query += localip;
    query += "\"";
    // insert into BaseInfo (ip,column) values ("192.168.xxxx",value)
    string insert = "insert into ";
    insert += table_name;
    insert += " (ip,";
    insert += column;
    insert += ") ";
    insert += "values (\"";
    insert += localip;
    insert += "\",";
    insert += to_string(value);
    insert += ")";
    // update BaseInfo set column=xxx where ip = "192.168.xxxx";
    string update = "update ";
    update += table_name;
    update += " set ";
    update += column;
    update += " = ";
    update += to_string(value);
    update += " where ip = \"";
    update += localip;
    update+="\"";
    if (!mysql_query(mysql,query.c_str())){
        result = mysql_store_result(mysql);
        // result->row_count
        if (!result->row_count){
            //null then insert...
            if (mysql_query(mysql,insert.c_str())){
                //error
                spdlog::critical("mysql error:{}",mysql_error(mysql));
                // logger->critical("mysql error:{}",mysql_error(mysql));
                mysql_free_result(result);
                mysql_close(mysql);
                return;
            }
            mysql_free_result(result);
            mysql_close(mysql);
            return;
        }
        else{
             // not null then update...
            // spdlog::info(update);
            if (mysql_query(mysql,update.c_str())){
                spdlog::critical("mysql error:{}",mysql_error(mysql));
                // logger->critical("mysql error:{}",mysql_error(mysql));
                mysql_free_result(result);
                mysql_close(mysql);
                return;
            }
            mysql_free_result(result);
            mysql_close(mysql);
            return;
        }
    }
}