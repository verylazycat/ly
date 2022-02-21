import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-securityframework-info',
  templateUrl: './securityframework-info.component.html',
  styleUrls: ['./securityframework-info.component.css']
})
export class SecurityframeworkInfoComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetFrameworkData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip
  }
  // 数据获取
  public FrameworkData:any = []

  GetFrameworkData(){
    this.service.GetFrameworkByIP(this.getIP()).subscribe((res)=>{
      this.FrameworkData = res
      console.log(res)
    })
  }
}
