import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-securitymydatabase',
  templateUrl: './securitymydatabase.component.html',
  styleUrls: ['./securitymydatabase.component.css']
})
export class SecuritymydatabaseComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetMydatabaseData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip
  }
  // 数据获取
  public MydatabaseData:any = []

  GetMydatabaseData(){
    this.service.GetMydatabaseByIP(this.getIP()).subscribe((res)=>{
      this.MydatabaseData = res
      console.log(res)
    })
  }
}
