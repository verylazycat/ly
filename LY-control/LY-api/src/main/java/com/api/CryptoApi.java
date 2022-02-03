package com.api;

import com.base.entity.Crypto;

import java.util.List;

public interface CryptoApi {
    List<Crypto> GetCryptoByIP(String ip);
}
