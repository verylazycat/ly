package com.base.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.annotation.TableField;
import java.io.Serializable;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * <p>
 *
 * </p>
 *
 * @author admin233
 * @since 2022-02-25
 */
@Data
@EqualsAndHashCode(callSuper = false)
@TableName("NetWorking")
public class Networking implements Serializable {

    private static final long serialVersionUID = 1L;

    private String ip;

    @TableField("IP_DOMAIN")
    private String ipDomain;

    @TableField("NicStatus")
    private String nicstatus;

    private String tcpStateSynSent;

    private String tcpStateSynRecv;

    private String tcpStateListening;

    private String tcpStateEstablished;

    private String tcpStateFinWaitOne;

    private String tcpStateCloseWait;

    private String tcpStateFinWaitTwo;

    private String tcpStateTimeWait;

    private String tcpStateLastAck;

    private String tcpStateClosing;

    private String arpInfo;


}
