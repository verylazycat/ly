import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecuritynetworkingComponent } from './securitynetworking.component';

describe('SecuritynetworkingComponent', () => {
  let component: SecuritynetworkingComponent;
  let fixture: ComponentFixture<SecuritynetworkingComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecuritynetworkingComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecuritynetworkingComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
