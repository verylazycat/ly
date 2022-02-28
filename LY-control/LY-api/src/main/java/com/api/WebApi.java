package com.api;

import com.base.entity.Web;

import java.util.List;

public interface WebApi {
    List<Web> GetWebByIP(String ip);
}
