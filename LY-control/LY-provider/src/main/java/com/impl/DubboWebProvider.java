package com.impl;

import com.api.WebApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Web;
import com.base.mapper.WebMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboWebProvider implements WebApi {
    @Autowired
    private WebMapper webMapper;

    @Override
    public List<Web> GetWebByIP(String ip) {
        QueryWrapper<Web> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Web> webList = webMapper.selectList(queryWrapper);
        return webList;
    }
}
