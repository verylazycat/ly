package com.api;

import com.base.entity.Nameservers;

import java.util.List;

public interface NameserversApi {
    List<Nameservers> GetNameserversByIP(String ip);
}
