import { Component, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';  // 用于获取路由参数
import { Location } from '@angular/common'; // 用于回退浏览记录
@Component({
  selector: 'app-status',
  templateUrl: './status.component.html',
  styleUrls: ['./status.component.css']
})

export class StatusComponent implements OnInit {
  constructor(
    private http: HttpClient,
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
    private location: Location) { }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip
  }
  ngOnInit(): void {
    //后台拉数据
    this.GetBaseInfoData()
    console.log(this.data)
    //初始化图形数据
    this.datainit()
  }
  // 数据获取
  public HostBaseInfo:any = []
  data : [number]= [0]
  GetBaseInfoData(){
    this.service.GetBaseInfoByIP(this.getIP()).subscribe((res)=>{
      this.HostBaseInfo = res
      // console.log(this.HostBaseInfo['0']['ip'])
      this.data.pop()
      this.data.push(this.HostBaseInfo["data"]['0']['bufferram'])
      this.data.push(this.HostBaseInfo["data"]['0']['freehigh'])
      this.data.push(this.HostBaseInfo["data"]['0']['freeswap'])
      this.data.push(this.HostBaseInfo["data"]['0']['memUnit'])
      this.data.push(this.HostBaseInfo["data"]['0']['pad'])
      this.data.push(this.HostBaseInfo["data"]['0']['sharedram'])
      this.data.push(this.HostBaseInfo["data"]['0']['totalhigh'])
      this.data.push(this.HostBaseInfo["data"]['0']['uptime'])
      this.data.push(this.HostBaseInfo["data"]['0']['procs'])
    })
  }
  // 基本信息可视化
  public options = {}
  datainit(){
    this.options={
      xAxis: {
        type: 'category',
        data: ['bufferram', 'freehigh', 'freeswap', 'memUnit', 'pad', 'sharedram', 'totalhigh','uptime','procs']
      },
      yAxis: {
        type: 'value'
      },
      series: [
        {
          name: 'value',
          stack: 'Total',
          label: {
            show: true,
            position: 'inside'
          },
          data : this.data,
          type: 'bar'
        }
      ]
    }
  }
  goback() {
    // 浏览器回退浏览记录
    this.location.back();
  }
}
