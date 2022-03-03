package com.controller;

import com.api.LoggingApi;
import com.api.MydatabaseApi;
import com.base.entity.Logging;
import com.base.entity.Mydatabase;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class MydatabaseController {
    @DubboReference
    private MydatabaseApi mydatabaseApi;
    @GetMapping("/MydatabaseInfo/{ip}")
    public ResponseResult getmydatabaseinfobyip(@PathVariable String ip){
        final List<Mydatabase> mydatabaseList = mydatabaseApi.GetMydatabaseByIP(ip);
        return ResponseResult.ok(mydatabaseList);
    }
}
