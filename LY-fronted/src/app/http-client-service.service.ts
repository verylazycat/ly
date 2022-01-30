import { Injectable } from '@angular/core';
import {HttpClient,HttpHeaders} from '@angular/common/http';
@Injectable({
  providedIn: 'root'
})
export class HttpClientServiceService {
  public BaseInfoApi = "http://localhost:3000/data"
  public GetBaseInfoByIPAPI = "http://localhost:3000/data?ip="
  public AuthByIPAPI = "http://localhost:4001/data?ip="
  public BootByIPAPI = "http://localhost:5000/data?ip="
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
}
