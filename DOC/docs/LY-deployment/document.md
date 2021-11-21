---
title: 文档部署
keywords: 文档部署
desc: 文档部署
---

## 安装python

```bash
sudo apt install python3 python3-pip git
```

`Windows` 和 `macOS`请到[官网下载](https://www.python.org/downloads/)

## 安装 teedoc

打开终端(`Windows`按`Ctrl+R`输入`cmd`)，输入：

```bash
sudo pip3 install teedoc
```

以后使用以下命令来更新软件

> 使用前务必同时更新软件和插件再使用，以防版本不同导致出现问题

```bash
sudo pip3 install -U teedoc
```

如果你的网络使用 `pypi.org` 速度很慢，可以选择其它源，比如清华 tuna 源： `pip3 install teedoc -i https://pypi.tuna.tsinghua.edu.cn/simple`

## 安装插件

这会根据`site_config.json`中的`plugins`的插件设置安装插件

```bash
cd DOC
teedoc install
```

## 构建 `HTML` 页面并起一个`HTTP`服务

```bash
teedoc serve
```

这个命令会先构建所有`HTML`页面以及拷贝资源文件，然后起一个`HTTP`服务,如果只需要生成页面，使用

```shell
teedoc build
```

在显示 `Starting server at 0.0.0.0:2333 ....` 后，就可以了

打开浏览器访问: [http://127.0.0.1:2333](http://127.0.0.1:2333/)

同时可以看到目录下多了一个`out`目录，里面就是生成的静态网站内容，直接拷贝到服务器使用`nginx`或者`apache`进行部署即可。

## 文档结构

因为 `teedoc` 特别为 多文档系统 设计， **有个基本概念， 每个文档工程包含了多份文档， 每份文档都有自己的配置文件名为 config** 需要先牢记

工程里面有几个重要文件：

- 工程根目录有`site_config.json`文件， 是工程的主要配置
- 工程里面可以有多份文档，在`site_config`的`route`配置项中设置，每份文档目录下面必须有`config.json`和`sidebar.json`(`json`文件也可以是`yaml`文件)， `config`文件负责这份文档的配置项，比如文档名称，多份文档可以使用`import`公用一份模板

## nginx 部署

### 安装 nginx

```bash
sudo apt update
sudo apt install nginx
```

### 配置并启动 nginx 服务

```bash
nginx -t
```

可以看到配置文件路径，一般是`/etc/nginx/nginx.conf`， 可以看到文件里面包含了`/etc/nginx/site-enabled/`

查看下面的`default`文件，可以看到语句

```none
listen 80 default_server;
root /var/www/html;
```

即监听`80`端口，网站根目录在这里，我们将我们的网站内容拷贝到这里，即`out`目录下所有文件拷贝到`/var/www/html/`目录下:

```none
service nginx start
```

访问`http://ip:80`就可以访问到网站了，`:80`也可以省略， 也可以修改成其它端口，因为国内没有备案的网站不允许使用`80`端口，海外的服务器则没有限制

> 详细参考：https://teedoc.neucrack.com/
