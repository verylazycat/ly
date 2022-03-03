import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecuritymydatabaseComponent } from './securitymydatabase.component';

describe('SecuritymydatabaseComponent', () => {
  let component: SecuritymydatabaseComponent;
  let fixture: ComponentFixture<SecuritymydatabaseComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecuritymydatabaseComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecuritymydatabaseComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
