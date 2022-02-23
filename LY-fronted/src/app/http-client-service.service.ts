import { Injectable } from '@angular/core';
import {HttpClient,HttpHeaders} from '@angular/common/http';
@Injectable({
  providedIn: 'root'
})
export class HttpClientServiceService {
  //gateway
  public host = "http://localhost:7777/"
  public BaseInfoApi = this.host + "api/BaseInfo/"
  public AuthAPI = this.host + "api/Auth/"
  public BootAPI = this.host + "api/BootInfo/"
  public CryptoAPI = this.host + "api/Cryptoinfo/"
  public FileintegrityAPI = this.host + "api/FileintegrityInfo/"
  public FirewallAPI = this.host + "api/FirewallInfo/"
  public FrameworkAPI = this.host + "api/FrameworkInfo/"
  public HardeningAPI = this.host + "api/HardeningInfo/"
  public kernelAPI = this.host + "api/KernelInfo/"
  public LoggingAPI = this.host + "api/LoggingInfo/"
  public NameserversAPI = this.host + "api/NameserversInfo/"
  constructor(
    public http: HttpClient
    ) { }
  GetBaseInfo(){
    return this.http.get(this.BaseInfoApi);
  }
  GetBaseInfoByIP(ip:string){
    console.log(this.BaseInfoApi+ip)
    return this.http.get(this.BaseInfoApi+ip);
  }
  GetAuthByIP(ip:string){
    return this.http.get(this.AuthAPI+ip)
  }
  GetBootByIP(ip:string){
    return this.http.get(this.BootAPI+ip)
  }
  GetCryptoByIP(ip:string){
    return this.http.get(this.CryptoAPI+ip)
  }
  GetFileintegrityByIP(ip:string){
    return this.http.get(this.FileintegrityAPI+ip)
  }
  GetFirewallByIP(ip:string){
    return this.http.get(this.FirewallAPI+ip)
  }
  GetFrameworkByIP(ip:string){
    return this.http.get(this.FrameworkAPI+ip)
  }
  GetHardeningByIP(ip:string){
    return this.http.get(this.HardeningAPI+ip)
  }
  GetKernelByIP(ip:string){
    return this.http.get(this.kernelAPI+ip)
  }
  GetLoggingByIP(ip:string){
    return this.http.get(this.LoggingAPI+ip)
  }
  GetNameserversByIP(ip:string){
    return this.http.get(this.NameserversAPI+ip)
  }
}
