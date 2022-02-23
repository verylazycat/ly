import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecurityloggingComponent } from './securitylogging.component';

describe('SecurityloggingComponent', () => {
  let component: SecurityloggingComponent;
  let fixture: ComponentFixture<SecurityloggingComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecurityloggingComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecurityloggingComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
