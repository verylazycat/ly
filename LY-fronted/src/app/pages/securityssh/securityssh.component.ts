import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-securityssh',
  templateUrl: './securityssh.component.html',
  styleUrls: ['./securityssh.component.css']
})
export class SecuritysshComponent implements OnInit {

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
  public SshData:any = []

  GetSshData(){
    this.service.GetSshByIP(this.getIP()).subscribe((res)=>{
      this.SshData = res
      console.log(res)
    })
  }
}
