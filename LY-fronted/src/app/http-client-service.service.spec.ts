import { TestBed } from '@angular/core/testing';

import { HttpClientServiceService } from './http-client-service.service';

describe('HttpClientServiceService', () => {
  let service: HttpClientServiceService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(HttpClientServiceService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
