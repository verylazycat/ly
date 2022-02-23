package com.impl;

import com.api.NameserversApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Nameservers;
import com.base.mapper.NameserversMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboNameserversProvider implements NameserversApi {
    @Autowired
    private NameserversMapper nameserversMapper;
    @Override
    public List<Nameservers> GetNameserversByIP(String ip) {
        QueryWrapper<Nameservers> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Nameservers> nameserversList = nameserversMapper.selectList(queryWrapper);
        return nameserversList;
    }
}
