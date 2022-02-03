package com.impl;

import com.api.FileintegrityApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Fileintegrity;
import com.base.mapper.FileintegrityMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboFileintegrityProvider implements FileintegrityApi {
    @Autowired
    FileintegrityMapper fileintegrityMapper;
    @Override
    public List<Fileintegrity> GetFileintegrityByIP(String ip) {
        QueryWrapper<Fileintegrity> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Fileintegrity> fileintegrityList = fileintegrityMapper.selectList(queryWrapper);
        return fileintegrityList;
    }
}
