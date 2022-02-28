import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecuritysquidComponent } from './securitysquid.component';

describe('SecuritysquidComponent', () => {
  let component: SecuritysquidComponent;
  let fixture: ComponentFixture<SecuritysquidComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecuritysquidComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecuritysquidComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
