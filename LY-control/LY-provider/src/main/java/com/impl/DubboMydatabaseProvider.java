package com.impl;

import com.api.MydatabaseApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Mydatabase;
import com.base.mapper.MydatabaseMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboMydatabaseProvider implements MydatabaseApi {
    @Autowired
    private MydatabaseMapper mydatabaseMapper;
    @Override
    public List<Mydatabase> GetMydatabaseByIP(String ip) {
        QueryWrapper<Mydatabase> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Mydatabase> mydatabaseList = mydatabaseMapper.selectList(queryWrapper);
        return mydatabaseList;
    }
}
