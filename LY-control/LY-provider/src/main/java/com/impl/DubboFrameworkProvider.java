package com.impl;

import com.api.FrameworkApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Framework;
import com.base.mapper.FrameworkMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboFrameworkProvider implements FrameworkApi {
    @Autowired
    FrameworkMapper frameworkMapper;
    @Override
    public List<Framework> GetFrameworkByIP(String ip) {
        QueryWrapper<Framework> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Framework> frameworkList = frameworkMapper.selectList(queryWrapper);
        return frameworkList;
    }
}
