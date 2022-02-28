package com.controller;

import com.api.NetworkingApi;
import com.base.entity.Networking;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class NetworkingController {
    @DubboReference
    private NetworkingApi networkingApi;
    @GetMapping("/NetworkingInfo/{ip}")
    public ResponseResult getnetworkinginfobyip(@PathVariable String ip){
        final List<Networking> networkingList = networkingApi.GetNetworkingByIP(ip);
        return ResponseResult.ok(networkingList);
    }
}
