package com.impl;

import com.api.KernelApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Kernel;
import com.base.mapper.KernelMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboKernelProvider implements KernelApi {
    @Autowired
    private KernelMapper kernelMapper;
    @Override
    public List<Kernel> GetKernelByIP(String ip) {
        QueryWrapper<Kernel> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Kernel> kernelList = kernelMapper.selectList(queryWrapper);
        return kernelList;
    }
}
