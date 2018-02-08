#include "IPlugEffect.h"
#include "IPlug_include_in_plug_src.h"
#include "IControls.h"
#include "config.h"

IPlugEffect::IPlugEffect(IPlugInstanceInfo instanceInfo)
: IPLUG_CTOR(kNumParams, kNumPrograms, instanceInfo)
{
  //TODO: implement! - Add parameters and controls
  //ADVANCED: make a custom IControl
  MakeDefaultPreset("-", kNumPrograms);
}

void IPlugEffect::ProcessBlock(sample** inputs, sample** outputs, int nFrames)
{
  //TODO: implement a volume control
  //ADVANCED: 1) make it stereo, 2) control the volume of sine wave harmonics (see oscillator.h)
}
