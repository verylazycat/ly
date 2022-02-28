package com.api;

import com.base.entity.Squid;

import java.util.List;

public interface SquidApi {
    List<Squid> GetSquidByIP(String ip);
}
