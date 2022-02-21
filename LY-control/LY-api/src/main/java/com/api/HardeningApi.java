package com.api;

import com.base.entity.Hardening;

import java.util.List;

public interface HardeningApi {
    List<Hardening> GetHardeningByIP(String ip);
}
