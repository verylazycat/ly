import { Component, OnInit } from '@angular/core';
import { HttpClientServiceService } from 'src/app/http-client-service.service';
import { HttpClient } from '@angular/common/http';
import { of } from 'rxjs';
@Component({
  selector: 'app-welcome',
  templateUrl: './welcome.component.html',
  styleUrls: ['./welcome.component.css']
})
export class WelcomeComponent implements OnInit {
  constructor(
    private http: HttpClient,
    private service: HttpClientServiceService) { }

  ngOnInit() {
    this.GetAllBaseInfo()
  }
  public BaseInfo:any = []
  GetAllBaseInfo(){
    this.service.GetBaseInfo().subscribe((res)=>{
      this.BaseInfo = res
    })
  }
  
}
