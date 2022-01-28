package com.impl;

import com.alibaba.csp.sentinel.annotation.SentinelResource;
import com.alibaba.csp.sentinel.slots.block.BlockException;
import com.api.BaseinfoApi;
import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
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
//    @SentinelResource(value = "DemoService#bonjour", defaultFallback = "bonjourFallback")
    public List<Baseinfo> GetAllBaseinfo() {
        final List<Baseinfo> list = baseinfoMapper.selectList(null);
        return list;
    }
    public String bonjourFallback(Throwable t) {
        if (BlockException.isBlockException(t)) {
            return "Blocked by Sentinel: " + t.getClass().getSimpleName();
        }
        return "Oops, failed: " + t.getClass().getCanonicalName();
    }
}
