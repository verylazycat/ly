import { Injectable } from '@angular/core';
import {HttpClient,HttpHeaders} from '@angular/common/http';
@Injectable({
  providedIn: 'root'
})
export class HttpClientServiceService {
  public BaseInfoApi = "http://localhost:3000/data"
  public GetBaseInfoByIPAPI = "http://localhost:3000/data?ip="
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
}
