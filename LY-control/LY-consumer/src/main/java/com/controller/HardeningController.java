package com.controller;

import com.api.HardeningApi;
import com.base.entity.Framework;
import com.base.entity.Hardening;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class HardeningController {
    @DubboReference
    private HardeningApi hardeningApi;
    @GetMapping("/HardeningInfo/{ip}")
    public ResponseResult gethardeninginfobyip(@PathVariable String ip){
        final List<Hardening> hardeningList = hardeningApi.GetHardeningByIP(ip);
        return ResponseResult.ok(hardeningList);
    }
}
