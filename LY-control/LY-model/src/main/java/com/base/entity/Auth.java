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
 * @since 2022-01-26
 */
@Data
@EqualsAndHashCode(callSuper = false)
@TableName("Auth")
public class Auth implements Serializable {

    private static final long serialVersionUID = 1L;

    private String ip;

    private String duplicatename;

    private Integer namesecurity;

    private String nopwuser;

    private Integer invalidcount;

    private Integer pwsecurity;

    private Integer currentUid;

    private Integer mode;

    private Integer safeCommonMode;

    private Integer safeSuperMode;


}
