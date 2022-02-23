import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-securitykernel',
  templateUrl: './securitykernel.component.html',
  styleUrls: ['./securitykernel.component.css']
})
export class SecuritykernelComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetkernelData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip
  }
  // 数据获取
  public kernelData:any = []

  GetkernelData(){
    this.service.GetKernelByIP(this.getIP()).subscribe((res)=>{
      this.kernelData = res
      console.log(res)
    })
  }
}
