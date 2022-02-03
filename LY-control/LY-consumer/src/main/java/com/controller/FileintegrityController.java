package com.controller;

import com.api.FileintegrityApi;
import com.base.entity.Crypto;
import com.base.entity.Fileintegrity;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class FileintegrityController {
    @DubboReference
    private FileintegrityApi fileintegrityApi;
    @GetMapping("/FileintegrityInfo/{ip}")
    public ResponseResult getfileintegrityinfobyip(@PathVariable String ip){
        final List<Fileintegrity> fileintegrityList = fileintegrityApi.GetFileintegrityByIP(ip);
        return ResponseResult.ok(fileintegrityList);
    }
}
