import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { ActivatedRoute } from '@angular/router';
@Component({
  selector: 'app-securitycrypto',
  templateUrl: './securitycrypto.component.html',
  styleUrls: ['./securitycrypto.component.css']
})
export class SecuritycryptoComponent implements OnInit {

  constructor(
    private service: HttpClientServiceService,
    private route: ActivatedRoute,
  ) { }

  ngOnInit(): void {
    this.GetCryptoInfoData()
  }
  //获取url参数ip值
  getIP(): string {
    const ip = String(this.route.snapshot.paramMap.get('ip'));
    return ip;
  }
  // 数据获取
  public CryptoData:any = []

  GetCryptoInfoData(){
    this.service.GetCryptoByIP(this.getIP()).subscribe((res)=>{
      this.CryptoData = res;
      console.log(this.CryptoData[0]);
    })
  }
}
