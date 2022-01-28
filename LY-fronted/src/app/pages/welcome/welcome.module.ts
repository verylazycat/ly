import { NgModule } from '@angular/core';

import { WelcomeRoutingModule } from './welcome-routing.module';

import { WelcomeComponent } from './welcome.component';
import { NzCardModule } from 'ng-zorro-antd/card';
import { CommonModule } from '@angular/common';
@NgModule({
  imports: [WelcomeRoutingModule,NzCardModule,CommonModule],
  declarations: [WelcomeComponent],
  exports: [WelcomeComponent]
})
export class WelcomeModule {
  gridStyle = {
    width: '25%',
    textAlign: 'center'
  };
}
