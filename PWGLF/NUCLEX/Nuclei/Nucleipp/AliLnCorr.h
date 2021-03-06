#ifndef ALILNCORR_H
#define ALILNCORR_H

/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

// driver for rebuilding the correction file
// author: Eulogio Serradilla <eulogio.serradilla@cern.ch>

#include <TObject.h>
#include <TString.h>

class AliLnSecondaries;
class AliLnEfficiency;

class AliLnCorr: public TObject
{
  public:
	
	AliLnCorr(const TString& particle, const TString& dataFilename, const TString& simuFilename, const TString& simuFixFilename, const TString& outputFilename, const TString& otag);
	virtual ~AliLnCorr();
	
	Int_t Exec();
	
	AliLnSecondaries* GetLnSecondaries() { return fSecondaries; }
	AliLnEfficiency*  GetLnEfficiency() { return fEfficiency; }
	
  private:
 
	AliLnCorr(const AliLnCorr& other);
	AliLnCorr& operator=(const AliLnCorr& other);
	
  private:
 
	TString fOutputFilename; // output filename
	
	AliLnSecondaries* fSecondaries; // secondaries correction
	AliLnEfficiency*  fEfficiency; // eficiency correction
	
	ClassDef(AliLnCorr,1)
};

#endif // ALILNCORR_H
