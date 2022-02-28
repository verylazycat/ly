import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecurityprocessesComponent } from './securityprocesses.component';

describe('SecurityprocessesComponent', () => {
  let component: SecurityprocessesComponent;
  let fixture: ComponentFixture<SecurityprocessesComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecurityprocessesComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecurityprocessesComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
