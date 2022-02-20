package com.api;

import com.base.entity.Auth;

import java.util.List;

public interface AuthApi {
    List<Auth> GetAllAuth();
    List<Auth> GetAuthByIP(String ip);
}
