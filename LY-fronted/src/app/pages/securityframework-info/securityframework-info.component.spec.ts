import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecurityframeworkInfoComponent } from './securityframework-info.component';

describe('SecurityframeworkInfoComponent', () => {
  let component: SecurityframeworkInfoComponent;
  let fixture: ComponentFixture<SecurityframeworkInfoComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecurityframeworkInfoComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecurityframeworkInfoComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
