package com.impl;

import com.api.SquidApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Squid;
import com.base.mapper.SquidMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboSquidProvider implements SquidApi {
    @Autowired
    private SquidMapper squidMapper;
    @Override
    public List<Squid> GetSquidByIP(String ip) {
        QueryWrapper<Squid> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Squid> squidList = squidMapper.selectList(queryWrapper);
        return squidList;
    }
}
