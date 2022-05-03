---
title: 调度中心部署
keywords: 调度中心部署
desc: 调度中心部署
---

## nacos部署

- 下载nacos：https://[github](https://so.csdn.net/so/search?q=github&spm=1001.2101.3001.7020).com/alibaba/nacos/releases
- 解压
- 进入bin目录
- 执行命令：

```bash
sh startup.sh -m standalone
```

打开浏览器进入：http://localhost:8848/nacos/

## sentinel 部署

- 下载jar：https://github.com/alibaba/Sentinel/releases
- 运行命令

```bash
java -Dserver.port=8081 -Dcsp.sentinel.dashboard.server=localhost:8081 -Dproject.name=sentinel-dashboard -jar sentinel-dashboard-1.6.3.jar
```

打开浏览器进入：http://localhost:8081

## test

- 进入`LY-control`目录
- 执行clean

```bash
mvn clean
```

>[INFO] Scanning for projects...
>...
>[INFO] LY-control ......................................... SUCCESS [  0.069 s]
>[INFO] LY-model ........................................... SUCCESS [  0.003 s]
>[INFO] LY-api ............................................. SUCCESS [  0.003 s]
>[INFO] LY-provider ........................................ SUCCESS [  0.015 s]
>[INFO] common ............................................. SUCCESS [  0.002 s]
>[INFO] LY-consumer ........................................ SUCCESS [  0.003 s]
>[INFO] LY-gateway ......................................... SUCCESS [  0.003 s]
>[INFO] ------------------------------------------------------------------------
>[INFO] BUILD SUCCESS

- 执行test

```bash
mvn test
```

> [INFO] Scanning for projects...
> [INFO] ------------------------------------------------------------------------
> [INFO] Reactor Build Order:
> [INFO] 
> [INFO] LY-control                                                         [pom]
> [INFO] LY-model                                                           [jar]
> [INFO] LY-api                                                             [jar]
> [INFO] LY-provider                                                        [jar]
> [INFO] common                                                             [jar]
> [INFO] LY-consumer                                                        [jar]
> [INFO] LY-gateway                                                         [jar]
>
> ...

## package

```bash
mvn package
```

## 运行

- provider

  - 进入LY-provider 下target目录，执行命令：

  ```bash
  java -jar LY-provider-1.0-SNAPSHOT.jar
  ```

- consumer

  - 进入LY-consumer下target目录，执行命令：

  ```bash
  java -jar LY-consumer-1.0-SNAPSHOT.jar
  ```

- gateway

  - 进入LY-gateway 下target目录，执行命令：

  ```bash
  java -jar LY-gateway-1.0-SNAPSHOT.jar
  ```

## 测试

执行命令：

```bash
curl http://localhost:7777/api/NetworkingInfo/192.168.1.112
```

```json
{"status":0,"msg":"sucess","data":[{"ip":"192.168.1.112","ipDomain":"127.0.0.1\tlocalhost|::1     ip6-localhost ip6-loopback|fe00::0 ip6-localnet|ff00::0 ip6-mcastprefix|ff02::1 ip6-allnodes|ff02::2 ip6-allrouters|140.82.113.26                 alive.github.com|140.82.113.25                 live.github.com|185.199.108.154               github.githubassets.com|140.82.114.22                 central.github.com|185.199.108.133               desktop.githubusercontent.com|185.199.108.153               assets-cdn.github.com|185.199.108.133               camo.githubusercontent.com|185.199.108.133               github.map.fastly.net|199.232.69.194                github.global.ssl.fastly.net|140.82.114.4                  gist.github.com|185.199.108.153               github.io|140.82.113.4                  github.com|192.0.66.2                    github.blog|140.82.113.5                  api.github.com|185.199.108.133               raw.githubusercontent.com|185.199.108.133               user-images.githubusercontent.com|185.199.108.133               favicons.githubusercontent.com|185.199.108.133               avatars5.githubusercontent.com|185.199.108.133               avatars4.githubusercontent.com|185.199.108.133               avatars3.githubusercontent.com|185.199.108.133               avatars2.githubusercontent.com|185.199.108.133               avatars1.githubusercontent.com|185.199.108.133               avatars0.githubusercontent.com|185.199.108.133               avatars.githubusercontent.com|140.82.114.9                  codeload.github.com|52.217.168.105                github-cloud.s3.amazonaws.com|52.217.130.233                github-com.s3.amazonaws.com|54.231.133.57                 github-production-release-asset-2e65be.s3.amazonaws.com|52.217.140.41                 github-production-user-asset-6210df.s3.amazonaws.com|52.216.109.219                github-production-repository-file-5c1aeb.s3.amazonaws.com|185.199.108.153               githubstatus.com|64.71.144.202                 github.community|23.100.27.125                 github.dev|140.82.113.22                 collector.github.com|13.107.43.16                  pipelines.actions.githubusercontent.com|185.199.108.133               media.githubusercontent.com|185.199.108.133               cloud.githubusercontent.com|185.199.108.133               objects.githubusercontent.com|","nicstatus":"docker0: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500\n        inet 172.17.0.1  netmask 255.255.0.0  broadcast 172.17.255.255\n        ether 02:42:46:3a:c3:0c  txqueuelen 0  (以太网)\n        RX packets 0  bytes 0 (0.0 B)\n        RX errors 0  dropped 0  overruns 0  frame 0\n        TX packets 0  bytes 0 (0.0 B)\n        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0\n\nenp3s0f1: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500\n        inet 192.168.1.112  netmask 255.255.255.0  broadcast 192.168.1.255\n        inet6 fe80::7779:78b9:b993:d223  prefixlen 64  scopeid 0x20<link>\n        ether 00:e0:4c:84:4e:64  txqueuelen 1000  (以太网)\n        RX packets 2066514  bytes 2421208423 (2.4 GB)\n        RX errors 0  dropped 0  overruns 0  frame 0\n        TX packets 1300723  bytes 124490629 (124.4 MB)\n        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0\n\nlo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536\n        inet 127.0.0.1  netmask 255.0.0.0\n        inet6 ::1  prefixlen 128  scopeid 0x10<host>\n        loop  txqueuelen 1000  (本地环回)\n        RX packets 2928107  bytes 513169816 (513.1 MB)\n        RX errors 0  dropped 0  overruns 0  frame 0\n        TX packets 2928107  bytes 513169816 (513.1 MB)\n        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0\n\n","tcpStateSynSent":"Recv-Q   Send-Q       Local Address:Port          Peer Address:Port   Process   \n0        1            192.168.1.112:40878       142.251.42.234:443              \n0        1            192.168.1.112:40176         45.43.32.234:443              \n0        1            192.168.1.112:40884       142.251.42.234:443              \n0        1            192.168.1.112:40172         45.43.32.234:443              \n0        1            192.168.1.112:40876       142.251.42.234:443              \n0        1            192.168.1.112:47908       142.251.42.237:443              \n0        1            192.168.1.112:47912       142.251.42.237:443              \n0        1            192.168.1.112:40882       142.251.42.234:443              \n","tcpStateSynRecv":"Recv-Q    Send-Q       Local Address:Port       Peer Address:Port    Process    \n","tcpStateListening":"Recv-Q    Send-Q       Local Address:Port        Peer Address:Port   Process    \n0         4096             127.0.0.1:27017            0.0.0.0:*                 \n0         511              127.0.0.1:6379             0.0.0.0:*                 \n0         511                0.0.0.0:80               0.0.0.0:*                 \n0         128              127.0.0.1:16308            0.0.0.0:*                 \n0         4096         127.0.0.53%lo:53               0.0.0.0:*                 \n0         5                127.0.0.1:631              0.0.0.0:*                 \n0         128                0.0.0.0:40599            0.0.0.0:*                 \n0         128              127.0.0.1:16090            0.0.0.0:*                 \n0         70                       *:33060                  *:*                 \n0         151                      *:3306                   *:*                 \n0         511                  [::1]:6379                [::]:*                 \n0         50                       *:8080                   *:*                 \n0         511                   [::]:80                  [::]:*                 \n0         5                    [::1]:631                 [::]:*                 \n0         256                      *:3128                   *:*                 \n","tcpStateEstablished":"Recv-Q   Send-Q      Local Address:Port          Peer Address:Port    Process   \n0        0               127.0.0.1:32876            127.0.0.1:33235             \n0        0           192.168.1.112:55476         39.136.94.93:443               \n0        0           192.168.1.112:38384       120.226.28.242:443               \n0        0           192.168.1.112:50840        164.52.110.14:443               \n0        0               127.0.0.1:33235            127.0.0.1:32876             \n0        0           192.168.1.112:55122         110.43.44.77:7826              \n0        0           192.168.1.112:44678         81.69.128.19:443               \n0        0               127.0.0.1:33164            127.0.0.1:44625             \n0        0               127.0.0.1:44625            127.0.0.1:33164             \n0        517         192.168.1.112:40174         45.43.32.234:443               \n0        0           192.168.1.112:37462       121.40.171.186:443               \n0        0           192.168.1.112:53158         120.92.84.16:9002              \n","tcpStateFinWaitOne":null,"tcpStateCloseWait":"Recv-Q    Send-Q       Local Address:Port       Peer Address:Port    Process    \n","tcpStateFinWaitTwo":null,"tcpStateTimeWait":"Recv-Q    Send-Q       Local Address:Port       Peer Address:Port    Process    \n","tcpStateLastAck":"Recv-Q    Send-Q       Local Address:Port       Peer Address:Port    Process    \n","tcpStateClosing":"Recv-Q  Send-Q             Local Address:Port       Peer Address:Port  Process  \n1       1         192.168.1.112%enp3s0f1:39974     35.232.111.17:80             \n","arpInfo":"地址                     类型    硬件地址            标志  Mask            接口\n192.168.1.1              ether   bc:5f:f6:fb:28:47   C                     enp3s0f1\n192.168.1.101            ether   dc:a2:66:40:85:75   C                     enp3s0f1\n记录: 2\t跳过: 0\t找到: 2\n"}],"url":null}
```

