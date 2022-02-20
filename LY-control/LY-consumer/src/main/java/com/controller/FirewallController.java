package com.controller;

import com.api.FileintegrityApi;
import com.api.FirewallApi;
import com.base.entity.Fileintegrity;
import com.base.entity.Firewall;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class FirewallController{
    @DubboReference
    private FirewallApi firewallApi;
    @GetMapping("/FirewallInfo/{ip}")
    public ResponseResult getfirewallinfobyip(@PathVariable String ip){
        final List<Firewall> firewallList = firewallApi.GetFirewallByIP(ip);
        return ResponseResult.ok(firewallList);
    }
}
