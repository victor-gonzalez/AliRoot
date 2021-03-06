//-*- Mode: C++ -*-
// $Id$
#ifndef ALIHLTGLOBALFLATESDTESTCOMPONENT_H
#define ALIHLTGLOBALFLATESDTESTCOMPONENT_H
//* This file is property of and copyright by the ALICE HLT Project        * 
//* ALICE Experiment at CERN, All rights reserved.                         *
//* See cxx source for full Copyright notice                               *

//  @file   AliHLTGlobalFlatEsdTestComponent.h
//  @author Matthias Richter
//  @date   
//  @brief  Global ESD converter component.
//  @note

#include "AliHLTProcessor.h"
#include "AliHLTComponentBenchmark.h"
#include <vector>


/**
 * @class AliHLTGlobalFlatEsdTestComponent
 * Global collector for information designated for the HLT ESD.
 *
 * componentid: \b GlobalEsdConverter <br>
 * componentlibrary: \b libAliHLTGlobal.so <br>
 * Arguments: <br>
 * <!-- NOTE: ignore the \li. <i> and </i>: it's just doxygen formatting -->
 * \li -notree                                                          <br>
 *      write ESD directly to output (::kAliHLTDataTypeESDObject)
 *      this has been made the default behavior in Sep 2008.
 * \li -tree                                                            <br>
 *      write ESD directly to TTree and to output (::kAliHLTDataTypeESDTree)
 * \li -skipobject=name1,name2,...                                   <br>
 *      comma separated list of ESD object names to be skipped, default is
 *      AliESDZDC,AliESDFMD,Cascades,Kinks,AliRawDataErrorLogs,AliESDACORDE
 *      leave blank to disable the option
 *
 * @ingroup alihlt_tpc_components
 */
class AliHLTGlobalFlatEsdTestComponent : public AliHLTProcessor
{
 public:
  /** standard constructor */
  AliHLTGlobalFlatEsdTestComponent();
  /** destructor */
  virtual ~AliHLTGlobalFlatEsdTestComponent();

  // interface methods of base class
  const char* GetComponentID() {return "GlobalFlatEsdTest";};
  void GetInputDataTypes(AliHLTComponentDataTypeList& list);
  AliHLTComponentDataType GetOutputDataType();
  void GetOutputDataSize(unsigned long& constBase, double& inputMultiplier);
  AliHLTComponent* Spawn() {return new AliHLTGlobalFlatEsdTestComponent;}

 protected:
  // interface methods of base class
  int DoInit(int argc, const char** argv);
  int DoDeinit();
  int DoEvent( const AliHLTComponentEventData& evtData,
	       const AliHLTComponentBlockData* blocks, 
	       AliHLTComponentTriggerData& trigData,
	       AliHLTUInt8_t* outputPtr, 
	       AliHLTUInt32_t& size,
	       AliHLTComponentBlockDataList& outputBlocks );

  using AliHLTProcessor::DoEvent;


 private:
  /** copy constructor prohibited */
  AliHLTGlobalFlatEsdTestComponent(const AliHLTGlobalFlatEsdTestComponent&);
  /** assignment operator prohibited */
  AliHLTGlobalFlatEsdTestComponent& operator=(const AliHLTGlobalFlatEsdTestComponent&);

  /**
   * (Re)Configure from the CDB
   * Loads the following objects:
   * - HLT/ConfigHLT/SolenoidBz
   */
  int Reconfigure(const char* cdbEntry, const char* chainId);

  /**
   * Configure the component.
   * Parse a string for the configuration arguments and set the component
   * properties.
   */
  int Configure(const char* arguments);

  int fWriteClusters; //!transient

  /// verbosity level
  int fVerbosity; //!transient

protected:

  /// solenoid b field
  Double_t fSolenoidBz; //! transient
  AliHLTComponentBenchmark fBenchmark; // benchmark

  ClassDef(AliHLTGlobalFlatEsdTestComponent, 0)
};
#endif
