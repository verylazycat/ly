package com.response;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class ResponseResult<T> implements Serializable {
    private static final long serialVersionUID = 1L;
    private int status;
    private String msg;
    private T data;
    private String url;
    public static ResponseResult ok(Object data){
        return new ResponseResult(StatusCode.OK,"sucess",data,null);
    }
}
