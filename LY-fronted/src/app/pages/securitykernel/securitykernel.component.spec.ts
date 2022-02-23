import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecuritykernelComponent } from './securitykernel.component';

describe('SecuritykernelComponent', () => {
  let component: SecuritykernelComponent;
  let fixture: ComponentFixture<SecuritykernelComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecuritykernelComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecuritykernelComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
