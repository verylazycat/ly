import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecuritycryptoComponent } from './securitycrypto.component';

describe('SecuritycryptoComponent', () => {
  let component: SecuritycryptoComponent;
  let fixture: ComponentFixture<SecuritycryptoComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecuritycryptoComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecuritycryptoComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
