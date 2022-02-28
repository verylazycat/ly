import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-securitysquid',
  templateUrl: './securitysquid.component.html',
  styleUrls: ['./securitysquid.component.css']
})
export class SecuritysquidComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetSquidData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip
  }
  // 数据获取
  public SquidData:any = []

  GetSquidData(){
    this.service.GetSquidByIP(this.getIP()).subscribe((res)=>{
      this.SquidData = res
      console.log(res)
    })
  }
}
