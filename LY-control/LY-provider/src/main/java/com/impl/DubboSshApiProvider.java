package com.impl;

import com.api.SshApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Ssh;
import com.base.mapper.SshMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboSshApiProvider implements SshApi {
    @Autowired
    private SshMapper sshMapper;

    @Override
    public List<Ssh> GetSshByIP(String ip) {
        QueryWrapper<Ssh> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Ssh> sshList = sshMapper.selectList(queryWrapper);
        return sshList;
    }
}
