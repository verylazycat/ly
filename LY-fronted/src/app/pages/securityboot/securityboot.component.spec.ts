import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecuritybootComponent } from './securityboot.component';

describe('SecuritybootComponent', () => {
  let component: SecuritybootComponent;
  let fixture: ComponentFixture<SecuritybootComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecuritybootComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecuritybootComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
