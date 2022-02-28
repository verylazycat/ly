import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-securityprinting',
  templateUrl: './securityprinting.component.html',
  styleUrls: ['./securityprinting.component.css']
})
export class SecurityprintingComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetPrintingData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip
  }
  // 数据获取
  public PrintingData:any = []

  GetPrintingData(){
    this.service.GetPrintingByIP(this.getIP()).subscribe((res)=>{
      this.PrintingData = res
      console.log(res)
    })
  }
}
