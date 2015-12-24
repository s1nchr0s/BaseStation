

#ifndef AutoTimer_h
#define AutoTimer_h

class AutoTimer{
  boolean set;                    // flag to check whether or not this timer has been set
  long eTime;                     // the end time for this timer, in units of the timing increment
  void (*eFunc)(int);             // the function to be called when timer expires
  int iParam;                     // the integer parameter to use in the funtion call for this timer
  
  static long cTime;              // cumulative number of timing increments since timerConfig was called
  
  public:
    AutoTimer(void (*eFunc)(int));      // creates timer that will call function eFunc, which must take a single integer parameter
    static void timerConfig();          // configures interrupt -- must be called before timers are used
    static void update();               // used by interrupt to increment cTime
  
    void setEvent(int csec,int iParam=0);   // sets a timing event such that when check() is called for this instance, eFunc(iParam) will be called after csec timing increments have passed 
    void check();                           // checks to see if this instance of autoTimer has been set, and if so whether the timer has expired
};

#endif
