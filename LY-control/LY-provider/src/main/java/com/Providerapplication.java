package com;

import org.apache.dubbo.config.spring.context.annotation.EnableDubbo;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@EnableDubbo
@SpringBootApplication
@MapperScan("com.base.mapper")
public class Providerapplication {
    public static void main(String[] args) {
        SpringApplication.run(Providerapplication.class,args);
    }
}
