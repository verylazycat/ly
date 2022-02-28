package com.impl;

import com.api.NetworkingApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Networking;
import com.base.mapper.NetworkingMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboNetworkingProvider implements NetworkingApi {
    @Autowired
    private NetworkingMapper networkingMapper;
    @Override
    public List<Networking> GetNetworkingByIP(String ip) {
        QueryWrapper<Networking> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Networking> networkingList = networkingMapper.selectList(queryWrapper);
        return networkingList;
    }
}
