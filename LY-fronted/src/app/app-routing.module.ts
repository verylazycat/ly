import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { StatusComponent } from './pages/status/status.component';
import { SecuritystatusComponent } from './pages/securitystatus/securitystatus.component';
import { SecuritybootComponent } from './pages/securityboot/securityboot.component';
import { SecuritycryptoComponent } from './pages/securitycrypto/securitycrypto.component';
import { SecurityfileintegrityComponent } from './pages/securityfileintegrity/securityfileintegrity.component';
const routes: Routes = [
  { path: '', pathMatch: 'full', redirectTo: '/welcome' },
  { path:'status/:ip',component:StatusComponent},
  { path: 'securitystatus/:ip',component:SecuritystatusComponent},
  { path: 'securityboot/:ip',component:SecuritybootComponent},
  { path: 'securitycrypto/:ip',component:SecuritycryptoComponent},
  { path: 'securityfileintegrity/:ip',component:SecurityfileintegrityComponent},
  { path: 'welcome', loadChildren: () => import('./pages/welcome/welcome.module').then(m => m.WelcomeModule) }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
