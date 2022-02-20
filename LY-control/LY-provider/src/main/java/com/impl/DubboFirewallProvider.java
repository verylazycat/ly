package com.impl;

import com.api.FirewallApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Firewall;
import com.base.mapper.FirewallMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboFirewallProvider implements FirewallApi {
    @Autowired
    private FirewallMapper firewallMapper;

    @Override
    public List<Firewall> GetFirewallByIP(String ip) {
        QueryWrapper<Firewall> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Firewall> firewallList = firewallMapper.selectList(queryWrapper);
        return firewallList;
    }
}
