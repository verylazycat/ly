package com.api;

import com.base.entity.Networking;

import java.util.List;

public interface NetworkingApi {
    List<Networking> GetNetworkingByIP(String ip);
}
