import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';
@Component({
  selector: 'app-securityweb',
  templateUrl: './securityweb.component.html',
  styleUrls: ['./securityweb.component.css']
})
export class SecuritywebComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetSshData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip
  }
  // 数据获取
  public WebData:any = []

  GetSshData(){
    this.service.GetWebByIP(this.getIP()).subscribe((res)=>{
      this.WebData = res
      console.log(res)
    })
  }
}
