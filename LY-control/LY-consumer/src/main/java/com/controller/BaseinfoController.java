package com.controller;

import com.api.BaseinfoApi;
import com.base.entity.Baseinfo;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class BaseinfoController {
    @DubboReference
    private BaseinfoApi baseinfoApi;
    @GetMapping("/BaseInfo")
    public ResponseResult getbaseinfo(){
        final List<Baseinfo> list = baseinfoApi.GetAllBaseinfo();
        return ResponseResult.ok(list);
    }
}
