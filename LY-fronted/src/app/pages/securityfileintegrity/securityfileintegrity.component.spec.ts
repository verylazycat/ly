import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecurityfileintegrityComponent } from './securityfileintegrity.component';

describe('SecurityfileintegrityComponent', () => {
  let component: SecurityfileintegrityComponent;
  let fixture: ComponentFixture<SecurityfileintegrityComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecurityfileintegrityComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecurityfileintegrityComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
