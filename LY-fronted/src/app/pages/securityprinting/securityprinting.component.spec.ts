import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecurityprintingComponent } from './securityprinting.component';

describe('SecurityprintingComponent', () => {
  let component: SecurityprintingComponent;
  let fixture: ComponentFixture<SecurityprintingComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecurityprintingComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecurityprintingComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
