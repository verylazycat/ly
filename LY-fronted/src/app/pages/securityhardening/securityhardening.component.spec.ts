import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecurityhardeningComponent } from './securityhardening.component';

describe('SecurityhardeningComponent', () => {
  let component: SecurityhardeningComponent;
  let fixture: ComponentFixture<SecurityhardeningComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecurityhardeningComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecurityhardeningComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
