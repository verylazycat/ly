package com.api;

import com.base.entity.Processes;

import java.util.List;

public interface ProcessesApi {
    List<Processes> GetProcessesByIP(String ip);
}
