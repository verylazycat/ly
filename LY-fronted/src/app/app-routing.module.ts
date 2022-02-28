import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { StatusComponent } from './pages/status/status.component';
import { SecuritystatusComponent } from './pages/securitystatus/securitystatus.component';
import { SecuritybootComponent } from './pages/securityboot/securityboot.component';
import { SecuritycryptoComponent } from './pages/securitycrypto/securitycrypto.component';
import { SecurityfileintegrityComponent } from './pages/securityfileintegrity/securityfileintegrity.component';
import { SecurityfirewallComponent } from './pages/securityfirewall/securityfirewall.component';
import { SecurityframeworkInfoComponent } from './pages/securityframework-info/securityframework-info.component';
import { SecurityhardeningComponent } from './pages/securityhardening/securityhardening.component';
import { SecuritykernelComponent } from './pages/securitykernel/securitykernel.component';
import { SecurityloggingComponent } from './pages/securitylogging/securitylogging.component';
import { SecuritynameserversComponent } from './pages/securitynameservers/securitynameservers.component';
import { SecuritynetworkingComponent } from './pages/securitynetworking/securitynetworking.component';
import { SecurityprintingComponent } from './pages/securityprinting/securityprinting.component';
import { SecurityprocessesComponent } from './pages/securityprocesses/securityprocesses.component';
import { SecuritysquidComponent } from './pages/securitysquid/securitysquid.component';
import { SecuritysshComponent } from './pages/securityssh/securityssh.component';
const routes: Routes = [
  { path: '', pathMatch: 'full', redirectTo: '/welcome' },
  { path:'status/:ip',component:StatusComponent},
  { path: 'securitystatus/:ip',component:SecuritystatusComponent},
  { path: 'securityboot/:ip',component:SecuritybootComponent},
  { path: 'securitycrypto/:ip',component:SecuritycryptoComponent},
  { path: 'securityfileintegrity/:ip',component:SecurityfileintegrityComponent},
  { path: 'securityfirewall/:ip',component:SecurityfirewallComponent},
  { path: 'securityframework/:ip',component:SecurityframeworkInfoComponent},
  { path: 'securityhardening/:ip',component:SecurityhardeningComponent},
  { path: 'securitykernel/:ip',component:SecuritykernelComponent},
  { path: 'securitylogging/:ip',component:SecurityloggingComponent},
  { path: 'securitynameservers/:ip',component:SecuritynameserversComponent},
  { path: 'securitynetworking/:ip',component:SecuritynetworkingComponent},
  { path: 'securityprinting/:ip',component:SecurityprintingComponent},
  { path: 'securityProcessesInfo/:ip',component:SecurityprocessesComponent},
  { path: 'securitySquid/:ip',component:SecuritysquidComponent},
  { path: 'securitySsh/:ip',component:SecuritysshComponent},
  { path: 'welcome', loadChildren: () => import('./pages/welcome/welcome.module').then(m => m.WelcomeModule) }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
