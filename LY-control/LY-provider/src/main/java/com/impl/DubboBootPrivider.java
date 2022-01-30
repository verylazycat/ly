package com.impl;

import com.api.BootApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Boot;
import com.base.mapper.BootMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboBootPrivider implements BootApi {
    @Autowired
    BootMapper bootMapper;
    @Override
    public List<Boot> GetBootByIP(String ip) {
        QueryWrapper<Boot> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Boot> Bootinfo = bootMapper.selectList(queryWrapper);
        return Bootinfo;
    }
}
