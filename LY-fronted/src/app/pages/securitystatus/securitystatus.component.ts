import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-securitystatus',
  templateUrl: './securitystatus.component.html',
  styleUrls: ['./securitystatus.component.css']
})
export class SecuritystatusComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetBaseInfoData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip
  }
  // 数据获取
  public AuthData:any = []

  GetBaseInfoData(){
    this.service.GetAuthByIP(this.getIP()).subscribe((res)=>{
      this.AuthData = res
    })
  }
}