package com.controller;

import com.api.KernelApi;
import com.base.entity.Kernel;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class KernelController {
    @DubboReference
    private KernelApi kernelApi;
    @GetMapping("/KernelInfo/{ip}")
    public ResponseResult getkernelinfobyip(@PathVariable String ip){
        final List<Kernel> kernelList = kernelApi.GetKernelByIP(ip);
        return ResponseResult.ok(kernelList);
    }
}
