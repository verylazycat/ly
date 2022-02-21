package com.impl;

import com.api.HardeningApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Hardening;
import com.base.mapper.HardeningMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboHardeningProvider implements HardeningApi {
    @Autowired
    HardeningMapper hardeningMapper;
    @Override
    public List<Hardening> GetHardeningByIP(String ip) {
        QueryWrapper<Hardening> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Hardening> hardeningList = hardeningMapper.selectList(queryWrapper);
        return hardeningList;
    }
}
