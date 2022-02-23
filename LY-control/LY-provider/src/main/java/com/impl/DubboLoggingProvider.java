package com.impl;

import com.api.LoggingApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Logging;
import com.base.mapper.LoggingMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboLoggingProvider implements LoggingApi {
    @Autowired
    private LoggingMapper loggingMapper;
    @Override
    public List<Logging> GetLoggingByIP(String ip) {
        QueryWrapper<Logging> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Logging> loggingList = loggingMapper.selectList(queryWrapper);
        return loggingList;
    }
}
