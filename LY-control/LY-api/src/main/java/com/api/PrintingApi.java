package com.api;

import com.base.entity.Printing;

import java.util.List;

public interface PrintingApi {
    List<Printing> GetPrintingByIP(String ip);
}
