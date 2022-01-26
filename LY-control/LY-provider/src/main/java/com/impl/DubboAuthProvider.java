package com.impl;

import com.api.AuthApi;
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
}
