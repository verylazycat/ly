import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-securitynameservers',
  templateUrl: './securitynameservers.component.html',
  styleUrls: ['./securitynameservers.component.css']
})
export class SecuritynameserversComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetNameserversData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip
  }
  // 数据获取
  public NameserversData:any = []

  GetNameserversData(){
    this.service.GetNameserversByIP(this.getIP()).subscribe((res)=>{
      this.NameserversData = res
      console.log(res)
    })
  }
}
