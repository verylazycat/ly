package com.api;

import com.base.entity.Fileintegrity;

import java.util.List;

public interface FileintegrityApi {
    List<Fileintegrity> GetFileintegrityByIP(String ip);
}
