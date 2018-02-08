#include "IPlugEffect.h"
#include "IPlug_include_in_plug_src.h"
#include "IControls.h"
#include "config.h"

IPlugEffect::IPlugEffect(IPlugInstanceInfo instanceInfo)
: IPLUG_CTOR(kNumParams, kNumPrograms, instanceInfo)
{
  TRACE;
  
  GetParam(kGain)->InitDouble("Gain", 0., 0., 100.0, 0.01, "%");

  // create graphics context
  IGraphics* pGraphics = MakeGraphics(*this, 300, 300);
  
  // add a coloured background
  pGraphics->AttachPanelBackground(COLOR_RED);
  
  // create a rectangular region for our control
  //                   L   T   W   H
  IRECT bounds = IRECT(10, 10, 50, 50);
  
  // create and attach control to the graphics context
  pGraphics->AttachControl(new IVKnobControl(*this, bounds, kGain));

  // attach graphics context
  AttachGraphics(pGraphics);
  
  MakeDefaultPreset("-", kNumPrograms);
}

void IPlugEffect::ProcessBlock(sample** inputs, sample** outputs, int nFrames)
{
  sample* input = inputs[0];
  sample* output = outputs[0];

  const double gain = GetParam(kGain)->Value() / 100.;

  for (int s = 0; s < nFrames; s++)
  {
    output[s] = input[s] * gain;
  }
}
