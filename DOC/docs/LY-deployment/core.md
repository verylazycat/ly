---
title: 核心部署
keywords: 核心部署
desc: 核心部署
---

## 源码下载

```bash
git clone git@github.com:verylazycat/ly.git
```

## 依赖配置

- base

```bash
sudo apt-get install gcc g++ cmake make
```

- openssl & libssl-dev

```bash
sudo apt install openssl libssl-dev -y
```

- libmysqlclient

```bash
sudo apt-get install libmysqlclient-dev
```

## 编译

进入源码目录，创建`build`文件夹

```bash
cd ly
mkdir build
```

进入`build`文件夹，进行编译链接

```bash
cd build
cmake ..
make -j8
```

## 运行

```bash
chmod +x LY
./LY
```

