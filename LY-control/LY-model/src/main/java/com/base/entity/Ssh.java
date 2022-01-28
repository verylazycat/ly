package com.base.entity;

import com.baomidou.mybatisplus.annotation.TableField;
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
@TableName("SSH")
public class Ssh implements Serializable {

    private static final long serialVersionUID = 1L;

    private String ip;

    private Integer confsecurity;

    @TableField("PasswordAuthentication")
    private Integer passwordauthentication;


}
