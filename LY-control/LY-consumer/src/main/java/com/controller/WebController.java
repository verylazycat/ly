package com.controller;

import com.api.SshApi;
import com.api.WebApi;
import com.base.entity.Ssh;
import com.base.entity.Web;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class WebController {
    @DubboReference
    private WebApi webApi;
    @GetMapping("/WebInfo/{ip}")
    public ResponseResult getwebinfobyip(@PathVariable String ip){
        final List<Web> webList = webApi.GetWebByIP(ip);
        return ResponseResult.ok(webList);
    }
}
