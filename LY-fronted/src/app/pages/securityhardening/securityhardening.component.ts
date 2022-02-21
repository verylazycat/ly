import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-securityhardening',
  templateUrl: './securityhardening.component.html',
  styleUrls: ['./securityhardening.component.css']
})
export class SecurityhardeningComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetHardeningData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip
  }
  // 数据获取
  public HardeningData:any = []

  GetHardeningData(){
    this.service.GetHardeningByIP(this.getIP()).subscribe((res)=>{
      this.HardeningData = res
      console.log(res)
    })
  }
}
