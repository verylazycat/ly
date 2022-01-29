import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { StatusComponent } from './status.component';
@NgModule({
  declarations: [StatusComponent],
  exports: [StatusComponent],
  imports: [
    CommonModule,
  ]
})
export class StatusModule { }
