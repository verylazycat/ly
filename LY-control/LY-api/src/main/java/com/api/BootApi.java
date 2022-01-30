package com.api;

import com.base.entity.Boot;

import java.util.List;

public interface BootApi {
    List<Boot> GetBootByIP(String ip);
}
