package com.controller;

import com.api.FrameworkApi;
import com.base.entity.Firewall;
import com.base.entity.Framework;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class FrameworkController {
    @DubboReference
    private FrameworkApi frameworkApi;
    @GetMapping("/FrameworkInfo/{ip}")
    public ResponseResult getframeworkinfobyip(@PathVariable String ip){
        final List<Framework> frameworkList = frameworkApi.GetFrameworkByIP(ip);
        return ResponseResult.ok(frameworkList);
    }
}
