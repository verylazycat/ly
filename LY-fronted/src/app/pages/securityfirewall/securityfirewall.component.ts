import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';
@Component({
  selector: 'app-securityfirewall',
  templateUrl: './securityfirewall.component.html',
  styleUrls: ['./securityfirewall.component.css']
})
export class SecurityfirewallComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetFirewallData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip;
  }
  // 数据获取
  public FirewallData:any = []

  GetFirewallData(){
    this.service.GetFirewallByIP(this.getIP()).subscribe((res)=>{
      this.FirewallData = res;
      console.log(this.FirewallData);
    })
  }
}
