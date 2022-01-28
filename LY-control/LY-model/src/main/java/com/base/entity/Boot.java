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
 * @since 2022-01-28
 */
@Data
@EqualsAndHashCode(callSuper = false)
@TableName("Boot")
public class Boot implements Serializable {

    private static final long serialVersionUID = 1L;

    private String ip;

    private Integer grubsecurity;

    private Integer grubencrypted;

    private Integer storedsecurely;

    private String cron;


}
