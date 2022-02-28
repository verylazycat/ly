package com.controller;

import com.api.ProcessesApi;
import com.base.entity.Processes;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class ProcessesController {
    @DubboReference
    private ProcessesApi processesApi;
    @GetMapping("/ProcessesInfo/{ip}")
    public ResponseResult getprocessesinfobyip(@PathVariable String ip){
        final List<Processes> processesList = processesApi.GetProcessesByIP(ip);
        return ResponseResult.ok(processesList);
    }
}
