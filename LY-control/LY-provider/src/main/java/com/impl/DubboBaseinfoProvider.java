package com.impl;

import com.api.BaseinfoApi;
import com.base.entity.Baseinfo;
import com.base.mapper.BaseinfoMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboBaseinfoProvider implements BaseinfoApi {
    @Autowired
    private BaseinfoMapper baseinfoMapper;
    @Override
    public List<Baseinfo> GetAllBaseinfo() {
        final List<Baseinfo> list = baseinfoMapper.selectList(null);
        return list;
    }
}
