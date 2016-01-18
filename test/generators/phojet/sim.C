void sim(Int_t nev=5) {
  // Libraries required by the simulation

  gSystem->Load("liblhapdf"); // Parton density functions
  gSystem->Load("libEGPythia6"); // TGenerator interface
  gSystem->Load("libpythia6"); // Pythia
  gSystem->Load("libAliPythia6"); // ALICE specific implementations
  gSystem->Load("libgeant321");

  gSystem->Load("libDPMJET"); // Parton density functions
  gSystem->Load("libTDPMjet"); // Parton density functions


  AliSimulation simulator;
  simulator.SetMakeSDigits("TRD TOF PHOS HMPID EMCAL MUON FMD ZDC PMD T0 VZERO");
  simulator.SetMakeDigitsFromHits("ITS TPC");
  simulator.SetWriteRawData("ALL","raw.root",kTRUE);

  simulator.SetDefaultStorage("local://$ALICE_ROOT/OCDB");
  simulator.SetSpecificStorage("GRP/GRP/Data",
			       Form("local://%s",gSystem->pwd()));
 
  TStopwatch timer;
  timer.Start();
  simulator.Run(nev);
  timer.Stop();
  timer.Print();
}