import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecurityfirewallComponent } from './securityfirewall.component';

describe('SecurityfirewallComponent', () => {
  let component: SecurityfirewallComponent;
  let fixture: ComponentFixture<SecurityfirewallComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecurityfirewallComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecurityfirewallComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
