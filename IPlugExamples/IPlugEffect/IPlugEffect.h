#pragma once

#include "IPlug_include_in_plug_hdr.h"

const int kNumPrograms = 1;

enum EParams
{
  kNumParams,
};

class IPlugEffect : public IPlug
{
public:
  IPlugEffect(IPlugInstanceInfo instanceInfo);
  void ProcessBlock(sample** inputs, sample** outputs, int nFrames) override;
};
