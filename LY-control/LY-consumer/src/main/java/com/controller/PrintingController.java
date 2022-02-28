package com.controller;


import com.api.PrintingApi;
import com.base.entity.Printing;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class PrintingController {
    @DubboReference
    private PrintingApi printingApi;
    @GetMapping("/PrintingInfo/{ip}")
    public ResponseResult getprintinginfobyip(@PathVariable String ip){
        final List<Printing> printingList = printingApi.GetPrintingByIP(ip);
        return ResponseResult.ok(printingList);
    }
}
