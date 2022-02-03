package com.controller;

import com.api.CryptoApi;
import com.base.entity.Boot;
import com.base.entity.Crypto;
import com.response.ResponseResult;
import org.apache.dubbo.config.annotation.DubboReference;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class CryptoController {
    @DubboReference
    private CryptoApi cryptoApi;
    @GetMapping("/Cryptoinfo/{ip}")
    public ResponseResult getcryptoinfobyip(@PathVariable String ip){
        final List<Crypto> cryptoList = cryptoApi.GetCryptoByIP(ip);
        return ResponseResult.ok(cryptoList);
    }
}
