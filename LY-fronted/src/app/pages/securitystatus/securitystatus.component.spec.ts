import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecuritystatusComponent } from './securitystatus.component';

describe('SecuritystatusComponent', () => {
  let component: SecuritystatusComponent;
  let fixture: ComponentFixture<SecuritystatusComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecuritystatusComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecuritystatusComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
