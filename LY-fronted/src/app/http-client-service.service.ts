import { Injectable } from '@angular/core';
import {HttpClient,HttpHeaders} from '@angular/common/http';
@Injectable({
  providedIn: 'root'
})
export class HttpClientServiceService {
  public BaseInfoApi = "http://localhost:3000/data"
  public GetBaseInfoByIPAPI = "http://localhost:3000/data?ip="
  public AuthByIPAPI = "http://localhost:3001/data?ip="
  public BootByIPAPI = "http://localhost:3002/data?ip="
  public CryptoByIPAPI = "http://localhost:3003/data?ip="
  public FileintegrityByIPAPI = "http://localhost:3004/data?ip="
  constructor(
    public http: HttpClient
    ) { }
  GetBaseInfo(){
    return this.http.get(this.BaseInfoApi);
  }
  GetBaseInfoByIP(ip:string){
    // console.log(this.GetBaseInfoByIPAPI+ip)
    return this.http.get(this.GetBaseInfoByIPAPI+ip);
  }
  GetAuthByIP(ip:string){
    console.log(this.AuthByIPAPI+ip)
    return this.http.get(this.AuthByIPAPI+ip)
  }
  GetBootByIP(ip:string){
    return this.http.get(this.BootByIPAPI+ip)
  }
  GetCryptoByIP(ip:string){
    return this.http.get(this.CryptoByIPAPI+ip)
  }
  GetFileintegrityByIP(ip:string){
    return this.http.get(this.FileintegrityByIPAPI+ip)
  }
}
