package com.api;

import com.base.entity.Framework;

import java.util.List;

public interface FrameworkApi {
    List<Framework> GetFrameworkByIP(String ip);
}
