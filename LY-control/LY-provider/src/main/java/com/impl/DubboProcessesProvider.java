package com.impl;

import com.api.ProcessesApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Processes;
import com.base.mapper.ProcessesMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboProcessesProvider implements ProcessesApi {
    @Autowired
    private ProcessesMapper processesMapper;
    @Override
    public List<Processes> GetProcessesByIP(String ip) {
        QueryWrapper<Processes> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Processes> processesList = processesMapper.selectList(queryWrapper);
        return  processesList;
    }
}
