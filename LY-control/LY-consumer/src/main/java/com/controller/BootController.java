package com.controller;

import com.api.BootApi;
import com.base.entity.Baseinfo;
import com.base.entity.Boot;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class BootController {
    @DubboReference
    private BootApi bootApi;
    @GetMapping("/BootInfo/{ip}")
    public ResponseResult getbaseinfobyip(@PathVariable String ip){
        final List<Boot> bootList = bootApi.GetBootByIP(ip);
        return ResponseResult.ok(bootList);
    }
}
