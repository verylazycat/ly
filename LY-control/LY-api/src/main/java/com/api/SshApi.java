package com.api;

import com.base.entity.Ssh;

import java.util.List;

public interface SshApi {
    List<Ssh> GetSshByIP(String ip);
}
