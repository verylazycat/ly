package com.controller;

import com.api.AuthApi;
import com.base.entity.Auth;
import com.base.entity.Baseinfo;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class AuthController {
    @DubboReference
    private AuthApi authApi;
    @GetMapping("/Auth")
    public ResponseResult getauth(){
        final List<Auth> list = authApi.GetAllAuth();
        return ResponseResult.ok(list);
    }
    @GetMapping("/Auth/{ip}")
    public ResponseResult getauthbyip(@PathVariable String ip){
        final List<Auth> authList = authApi.GetAuthByIP(ip);
        return  ResponseResult.ok(authList);
    }
}
