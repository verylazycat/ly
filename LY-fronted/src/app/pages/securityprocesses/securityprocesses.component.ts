import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-securityprocesses',
  templateUrl: './securityprocesses.component.html',
  styleUrls: ['./securityprocesses.component.css']
})
export class SecurityprocessesComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetProcessesData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip
  }
  // 数据获取
  public ProcessesData:any = []

  GetProcessesData(){
    this.service.GetProcessesByIP(this.getIP()).subscribe((res)=>{
      this.ProcessesData = res
      console.log(res)
    })
  }
}
