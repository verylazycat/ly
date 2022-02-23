package com.api;

import com.base.entity.Kernel;

import java.util.List;

public interface KernelApi {
    List<Kernel> GetKernelByIP(String ip);
}
