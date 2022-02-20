package com.impl;

import com.api.AuthApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Auth;
import com.base.mapper.AuthMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboAuthProvider implements AuthApi {
    @Autowired
    private AuthMapper authMapper;
    @Override
    public List<Auth> GetAllAuth() {
        final List<Auth> list = authMapper.selectList(null);
        return list;
    }

    @Override
    public List<Auth> GetAuthByIP(String ip) {
        QueryWrapper<Auth> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Auth> authList = authMapper.selectList(queryWrapper);
        return  authList;
    }
}
