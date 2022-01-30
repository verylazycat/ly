import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { NZ_I18N } from 'ng-zorro-antd/i18n';
import { zh_CN } from 'ng-zorro-antd/i18n';
import { registerLocaleData } from '@angular/common';
import zh from '@angular/common/locales/zh';
import { FormsModule } from '@angular/forms';
import { HttpClientModule } from '@angular/common/http';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';
import { IconsProviderModule } from './icons-provider.module';
import { NzLayoutModule } from 'ng-zorro-antd/layout';
import { NzMenuModule } from 'ng-zorro-antd/menu';
import { StatusComponent } from './pages/status/status.component';
import { NgxEchartsModule } from 'ngx-echarts';
import * as echarts from 'echarts'
import { NzTableModule } from 'ng-zorro-antd/table';
import { SecuritystatusComponent } from './pages/securitystatus/securitystatus.component';
import { NzTagModule } from 'ng-zorro-antd/tag';
import { SecuritybootComponent } from './pages/securityboot/securityboot.component';

registerLocaleData(zh);

@NgModule({
  declarations: [
    AppComponent,
    StatusComponent,
    SecuritystatusComponent,
    SecuritybootComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule,
    HttpClientModule,
    BrowserAnimationsModule,
    IconsProviderModule,
    NzLayoutModule,
    NzMenuModule,
    NzTableModule,
    NzTagModule,
    NgxEchartsModule.forRoot({
      echarts
    })
  ],
  providers: [{ provide: NZ_I18N, useValue: zh_CN }],
  bootstrap: [AppComponent]
})
export class AppModule { }
