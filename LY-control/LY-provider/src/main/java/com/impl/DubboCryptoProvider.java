package com.impl;

import com.api.CryptoApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Crypto;
import com.base.mapper.CryptoMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboCryptoProvider implements CryptoApi {
    @Autowired
    CryptoMapper cryptoMapper;
    @Override
    public List<Crypto> GetCryptoByIP(String ip) {
        QueryWrapper<Crypto> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Crypto> cryptoList = cryptoMapper.selectList(queryWrapper);
        return cryptoList;
    }
}
