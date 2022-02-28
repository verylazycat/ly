package com.controller;

import com.api.ProcessesApi;
import com.api.SquidApi;
import com.base.entity.Processes;
import com.base.entity.Squid;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class SquidController {
    @DubboReference
    private SquidApi squidApi;
    @GetMapping("/SquidInfo/{ip}")
    public ResponseResult getsquidinfobyip(@PathVariable String ip){
        final List<Squid> squidList = squidApi.GetSquidByIP(ip);
        return ResponseResult.ok(squidList);
    }
}
