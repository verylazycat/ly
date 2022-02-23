import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-securitylogging',
  templateUrl: './securitylogging.component.html',
  styleUrls: ['./securitylogging.component.css']
})
export class SecurityloggingComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetLoggingInfoData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip
  }
  // 数据获取
  public LoggingData:any = []

  GetLoggingInfoData(){
    this.service.GetLoggingByIP(this.getIP()).subscribe((res)=>{
      this.LoggingData = res
      console.log(res)
    })
  }
}
