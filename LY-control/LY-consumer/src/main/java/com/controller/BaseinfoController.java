package com.controller;

import com.api.BaseinfoApi;
import com.base.entity.Baseinfo;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.websocket.server.PathParam;
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
    @GetMapping("/BaseInfo/{ip}")
    public ResponseResult getbaseinfobyip(@PathVariable String ip){
        final List<Baseinfo> baseinfos = baseinfoApi.GetBaseInfoByIP(ip);
        return ResponseResult.ok(baseinfos);
    }
}
