struct Oscillator
{
  double mPhase = 0.;                        // float phase (goes between 0. and 1.)
  double mPhaseIncr = (1./44100.) * 440.;    // how much to add to the phase on each sample

  inline double process()
  {
    mPhase = mPhase + mPhaseIncr;
    return std::sin(mPhase * 6.283185307179586);
  }

  void setFreq(double freqHz)
  {
    mPhaseIncr = (1./44100.) * freqHz;
  }
};