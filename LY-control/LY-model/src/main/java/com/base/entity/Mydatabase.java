package com.base.entity;

import lombok.Data;
import lombok.EqualsAndHashCode;

import java.io.Serializable;

/**
 * <p>
 * 
 * </p>
 *
 * @author admin233
 * @since 2022-03-03
 */
@Data
@EqualsAndHashCode(callSuper = false)
public class Mydatabase implements Serializable {

    private static final long serialVersionUID = 1L;

    private String ip;

    private Integer ismysqlpwempty;

    private Integer redisflushall;

    private Integer redisconfig;

    private Integer rediseval;

    private Integer redispw;

    private Integer extranetredis;


}
