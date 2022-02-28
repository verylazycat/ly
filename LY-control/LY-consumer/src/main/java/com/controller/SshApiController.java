package com.controller;

import com.api.SquidApi;
import com.api.SshApi;
import com.base.entity.Squid;
import com.base.entity.Ssh;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class SshApiController {
    @DubboReference
    private SshApi sshApi;
    @GetMapping("/SshInfo/{ip}")
    public ResponseResult getsshinfobyip(@PathVariable String ip){
        final List<Ssh> sshList = sshApi.GetSshByIP(ip);
        return ResponseResult.ok(sshList);
    }
}
