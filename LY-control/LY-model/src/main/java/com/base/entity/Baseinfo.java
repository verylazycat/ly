package com.base.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.io.Serializable;

/**
 * <p>
 * 
 * </p>
 *
 * @author admin233
 * @since 2022-01-03
 */
@Data
@EqualsAndHashCode(callSuper = false)
@TableName("BaseInfo")
public class Baseinfo implements Serializable {

    private static final long serialVersionUID = 1L;

    private String domainname;

    private String machine;

    private String sysrelease;

    private String sysname;

    private String version;

    private Long bufferram;

    private String freehigh;

    private Long freeswap;

    private Integer memUnit;

    private Integer pad;

    private Long sharedram;

    private Integer totalhigh;

    private Integer uptime;

    private Integer procs;

    private String ip;


}
