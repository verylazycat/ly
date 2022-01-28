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
@TableName("Kernel")
public class Kernel implements Serializable {

    private static final long serialVersionUID = 1L;

    private String ip;

    @TableField("PAE")
    private Integer pae;

    private Integer coreDump;


}
