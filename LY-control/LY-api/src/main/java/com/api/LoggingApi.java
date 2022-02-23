package com.api;

import com.base.entity.Logging;

import java.util.List;

public interface LoggingApi {
    List<Logging> GetLoggingByIP(String ip);
}
