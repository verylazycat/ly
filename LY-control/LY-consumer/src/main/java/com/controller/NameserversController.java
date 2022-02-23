package com.controller;

import com.api.NameserversApi;
import com.base.entity.Logging;
import com.base.entity.Nameservers;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class NameserversController {
    @DubboReference
    private NameserversApi nameserversApi;
    @GetMapping("/NameserversInfo/{ip}")
    public ResponseResult getnameserversinfobyip(@PathVariable String ip){
        final List<Nameservers> nameserversList = nameserversApi.GetNameserversByIP(ip);
        return ResponseResult.ok(nameserversList);
    }
}
