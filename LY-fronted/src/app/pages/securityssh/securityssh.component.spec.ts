import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecuritysshComponent } from './securityssh.component';

describe('SecuritysshComponent', () => {
  let component: SecuritysshComponent;
  let fixture: ComponentFixture<SecuritysshComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecuritysshComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecuritysshComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
