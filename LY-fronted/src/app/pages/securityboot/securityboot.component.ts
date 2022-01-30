import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';
@Component({
  selector: 'app-securityboot',
  templateUrl: './securityboot.component.html',
  styleUrls: ['./securityboot.component.css']
})
export class SecuritybootComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetBootInfoData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip;
  }
  // 数据获取
  public BootData:any = []

  GetBootInfoData(){
    this.service.GetBootByIP(this.getIP()).subscribe((res)=>{
      this.BootData = res;
      console.log(this.BootData);
    })
  }
}
