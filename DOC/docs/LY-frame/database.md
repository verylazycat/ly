---
title: 数据库
keywords: 数据库
desc: 数据库
---

## 数据库信息

## LY-core

### BaseInfo

| 字段名     | 描述 |
| ---------- | ---- |
| domainname |      |
| machine    |      |
| sysrelease |      |
| sysname    |      |
| version    |      |
| bufferram  |      |
| freehigh   |      |
| freeswap   |      |
| mem_unit   |      |
| pad        |      |
| sharedram  |      |
| totalhigh  |      |
| uptime     |      |
| procs      |      |
| ip         |      |

### Auth

| 字段名           | 描述                  |
| ---------------- | --------------------- |
| ip               | ip地址                |
| duplicatename    | 重复的用户名          |
| namesecurity     | 用户名是否安全        |
| nopwuser         | 无密码的用户          |
| invalidcount     | 无密码用户数量        |
| pwsecurity       | 所有用户是否都有密码  |
| current_uid      | 当前用户uid           |
| mode             | 当前环境umask         |
| safe_common_mode | 普通用户umask是否安全 |
| safe_super_mode  | 超级用户umask是否安全 |

### Boot

| 字段名         | 描述               |
| -------------- | ------------------ |
| ip             | ip地址             |
| grubsecurity   | grub是否安全初始化 |
| grubencrypted  | grub是否加密       |
| storedsecurely | grub是否安全存储   |
| cron           | 计划任务列表       |

### Crypto

| 字段名 | 描述           |
| ------ | -------------- |
| ip     | ip地址         |
| total  | 过期的证书数量 |

### Printing

| 字段名                 | 描述             |
| ---------------------- | ---------------- |
| ip                     | ip地址           |
| CUPSpermissionsecurity | CUPS权限是否安全 |
| Remote                 | CUPS是否开启远程 |
| safeconfiguration      | CUPS配置是否安全 |
| WebInterface           | 网络接口         |

### Logging

| 字段名          | 描述                 |
| --------------- | -------------------- |
| ip              | ip地址               |
| tcpudpreception | 是否开启tcp，udp接收 |

### Nameservers

| 字段名     | 描述            |
| ---------- | --------------- |
| ip         | ip地址          |
| DNSdefault | DNS是否是默认值 |

FOREIGN KEY(ip) REFERENCES BaseInfo(ip)
