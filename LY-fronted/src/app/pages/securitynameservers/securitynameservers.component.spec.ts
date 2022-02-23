import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecuritynameserversComponent } from './securitynameservers.component';

describe('SecuritynameserversComponent', () => {
  let component: SecuritynameserversComponent;
  let fixture: ComponentFixture<SecuritynameserversComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecuritynameserversComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecuritynameserversComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
