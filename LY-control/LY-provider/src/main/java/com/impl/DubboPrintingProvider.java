package com.impl;

import com.api.PrintingApi;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.base.entity.Printing;
import com.base.mapper.PrintingMapper;
import org.apache.dubbo.config.annotation.DubboService;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

@DubboService
public class DubboPrintingProvider implements PrintingApi {
    @Autowired
    private PrintingMapper printingMapper;
    @Override
    public List<Printing> GetPrintingByIP(String ip) {
        QueryWrapper<Printing> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("ip",ip);
        final List<Printing> printingList = printingMapper.selectList(queryWrapper);
        return printingList;
    }
}
