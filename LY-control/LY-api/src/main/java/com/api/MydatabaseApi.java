package com.api;

import com.base.entity.Mydatabase;

import java.util.List;

public interface MydatabaseApi {
    List<Mydatabase> GetMydatabaseByIP(String ip);
}
