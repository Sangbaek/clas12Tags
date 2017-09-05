#ifndef HTCC_HITPROCESS_H
#define HTCC_HITPROCESS_H 1

// gemc headers
#include "HitProcess.h"

// constants to be used in the digitization routine
class htccConstants
{
public:

	// database
	int    runNo;
	string variation;
	string date;
	string connection;
        char   database[80];

	// translation table
	TranslationTable TT;

	// add constants here
	// status:                                                                                                                                                          
        //      0 - fully functioning                                                                                                                                       
        //      1 - noADC                                                                                                                                                   
        //      2 - noTDC                                                                                                                                                   
        //      3 - noADC, noTDC (PMT is dead)                                                                                                                              
        //      5 - any other reconstruction problem                                                                                                                        
        vector<int> status[6][2];

	// veff: time shift
        vector<double> tshift[6][2];


};



// Class definition
class htcc_HitProcess : public HitProcess
{
public:

	~htcc_HitProcess(){;}

	// - integrateDgt: returns digitized information integrated over the hit
	map<string, double> integrateDgt(MHit*, int);

	// - multiDgt: returns multiple digitized information / hit
	map< string, vector <int> > multiDgt(MHit*, int);

	// - charge: returns charge/time digitized information / step
	virtual map< int, vector <double> > chargeTime(MHit*, int);

	// - voltage: returns a voltage value for a given time. The input are charge value, time
	virtual double voltage(double, double, double);
	
	// The pure virtual method processID returns a (new) identifier
	// containing hit sharing information
	vector<identifier> processID(vector<identifier>, G4Step*, detector);

	// creates the HitProcess
	static HitProcess *createHitClass() {return new htcc_HitProcess;}

private:

	// constants initialized with initWithRunNumber
	static htccConstants htccc;

	void initWithRunNumber(int runno);

	// - electronicNoise: returns a vector of hits generated / by electronics.
	vector<MHit*> electronicNoise();

};

#endif
