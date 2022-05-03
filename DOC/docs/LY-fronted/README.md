---
title: 前端设计
keywords: 前端设计
desc: 前端设计
---

## 项目结构

```bash
➜  src git:(master) ✗ tree -L 3
.
├── app
│   ├── app.component.css
│   ├── app.component.html
│   ├── app.component.spec.ts
│   ├── app.component.ts
│   ├── app.module.ts
│   ├── app-routing.module.ts
│   ├── http-client-service.service.spec.ts
│   ├── http-client-service.service.ts
│   ├── icons-provider.module.ts
│   └── pages
│       ├── securityboot
│       ├── securitycrypto
│       ├── securityfileintegrity
│       ├── securityfirewall
│       ├── securityframework-info
│       ├── securityhardening
│       ├── securitykernel
│       ├── securitylogging
│       ├── securitymydatabase
│       ├── securitynameservers
│       ├── securitynetworking
│       ├── securityprinting
│       ├── securityprocesses
│       ├── securitysquid
│       ├── securityssh
│       ├── securitystatus
│       ├── securityweb
│       ├── status
│       └── welcome
├── assets
│   ├── Auth.json
│   ├── BaseInfo.json
│   ├── bg-pc.png
│   ├── Boot.json
│   ├── Crypto.json
│   ├── Fileintegrity.json
│   └── Firewall.json
├── Auth.json
├── environments
│   ├── environment.prod.ts
│   └── environment.ts
├── favicon.ico
├── index.html
├── main.ts
├── polyfills.ts
├── styles.css
├── test.ts
└── theme.less
23 directories, 26 files
```

- app.*:项目组织核心
- app-routing：路由模块
- http-client-service.service.ts：网络服务
- pages/*:各个页面模块
- assets/*：资源模块

