import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';
@Component({
  selector: 'app-securitynetworking',
  templateUrl: './securitynetworking.component.html',
  styleUrls: ['./securitynetworking.component.css']
})
export class SecuritynetworkingComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetNetworkingData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip
  }
  // 数据获取
  public NetworkingData:any = []

  GetNetworkingData(){
    this.service.GetNetworkingByIP(this.getIP()).subscribe((res)=>{
      this.NetworkingData = res
      console.log(res)
    })
  }
}
