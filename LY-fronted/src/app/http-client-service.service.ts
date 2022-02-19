import { Injectable } from '@angular/core';
import {HttpClient,HttpHeaders} from '@angular/common/http';
@Injectable({
  providedIn: 'root'
})
export class HttpClientServiceService {
  // mock
  // public BaseInfoApi = "http://localhost:3000/data"
  // public GetBaseInfoByIPAPI = "http://localhost:3000/data?ip="
  public BaseInfoApi = "http://localhost:7777/api/BaseInfo/"
  // public GetBaseInfoByIPAPI = "http://localhost:7777/api/BaseInfo/"
  public AuthByIPAPI = "http://localhost:3001/data?ip="
  public BootByIPAPI = "http://localhost:3002/data?ip="
  public CryptoByIPAPI = "http://localhost:3003/data?ip="
  public FileintegrityByIPAPI = "http://localhost:3004/data?ip="
  constructor(
    public http: HttpClient
    ) { }
  GetBaseInfo(){
    // return this.http.jsonp(this.BaseInfoApi,'callback')
    return this.http.get(this.BaseInfoApi);
  }
  GetBaseInfoByIP(ip:string){
    console.log(this.BaseInfoApi+ip)
    return this.http.get(this.BaseInfoApi+ip);
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
