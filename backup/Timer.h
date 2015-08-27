#ifndef __CLOCK
#define __CLOCK

extern "C" int _stdcall GetTickCount();

class Timer{      	
	public:       
	    Timer();
	    ~Timer();
	    
	    //FUNCTIONS
	    void  init();
		float GetEllapsedTime();
		void  reset();
	    
	private:
		//VARS
	    double start;
}; 

#endif //__CLOCK
