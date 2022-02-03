import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';
@Component({
  selector: 'app-securityfileintegrity',
  templateUrl: './securityfileintegrity.component.html',
  styleUrls: ['./securityfileintegrity.component.css']
})
export class SecurityfileintegrityComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetFileintegrityInfoData();
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip;
  }
  // 数据获取
  public FileintegrityData:any = []

  GetFileintegrityInfoData(){
    this.service.GetFileintegrityByIP(this.getIP()).subscribe((res)=>{
      this.FileintegrityData = res;
      console.log(this.FileintegrityData[0]);
    })
  }
}
