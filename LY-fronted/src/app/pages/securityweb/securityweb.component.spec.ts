import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecuritywebComponent } from './securityweb.component';

describe('SecuritywebComponent', () => {
  let component: SecuritywebComponent;
  let fixture: ComponentFixture<SecuritywebComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SecuritywebComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SecuritywebComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
