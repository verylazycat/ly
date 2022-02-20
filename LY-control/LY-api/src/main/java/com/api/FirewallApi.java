package com.api;

import com.base.entity.Firewall;

import java.util.List;

public interface FirewallApi {
    List<Firewall> GetFirewallByIP(String ip);
}
