package com.controller;

import com.api.KernelApi;
import com.api.LoggingApi;
import com.base.entity.Kernel;
import com.base.entity.Logging;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class LoggingController {
    @DubboReference
    private LoggingApi loggingApi;
    @GetMapping("/LoggingInfo/{ip}")
    public ResponseResult getlogginginfobyip(@PathVariable String ip){
        final List<Logging> loggingList = loggingApi.GetLoggingByIP(ip);
        return ResponseResult.ok(loggingList);
    }
}
