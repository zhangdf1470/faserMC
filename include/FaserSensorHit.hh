#ifndef FaserSensorHit_h
#define FaserSensorHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4AffineTransform.hh"
#include "FaserDetectorConstruction.hh"
#include "tls.hh"

// Hit class for the Faser silicon sensor
//
// Stores:
//
// trackID
// planeID
// moduleID
// sensorID
// rowID
// stripID
// energy deposit
// global position
// local position

class FaserSensorHit : public G4VHit
{
   public:

    FaserSensorHit();
    FaserSensorHit(const FaserSensorHit&);
    virtual ~FaserSensorHit();

    const FaserSensorHit& operator=(const FaserSensorHit&);
    G4int operator==(const FaserSensorHit&);

    inline void* operator new(size_t);
    inline void  operator delete(void*);

    // over-ridden methods
    virtual void Draw();
    virtual void Print();

    // setters
    void SetPlaneID(G4int plane)               		{ fPlaneID = plane; };
    void SetModuleID(G4int module) 	            	{ fModuleID = module; };
    void SetSensorID(G4int sensor)      	       	{ fSensorID = sensor; };
    void SetRowID(G4int row)                   		{ fRowID = row; };
    void SetStripID(G4int strip)	               	{ fStripID = strip; };
    void SetEdep(G4double de)           	       	{ fEdep = de; };
    void SetGlobalPos(G4ThreeVector globalXYZ) 		{ fGlobalPos = globalXYZ; };
    void SetLocalPos(G4ThreeVector localXYZ)   		{ fLocalPos = localXYZ; };
    void SetTransform(G4AffineTransform transform)      { fTransform = transform; };  
  
    void SetTrackID(G4int track)			{ fTrackID = track; };
    void SetParticle(G4int particle)			{ fParticle = particle; };
    void SetVertex(G4ThreeVector xyz)		        { fOriginPosition = xyz; };
    void SetMomentum(G4ThreeVector xyz)	                { fOriginMomentum = xyz; };
    void SetTotalEnergy(G4double te)   		        { fOriginEnergy = te; };

    // getters
    G4int GetPlaneID() const    	       		{ return fPlaneID; };
    G4int GetModuleID() const          			{ return fModuleID; };
    G4int GetSensorID() const          			{ return fSensorID; };
    G4int GetRowID() const	             		{ return fRowID; };
    G4int GetStripID() const    	       		{ return fStripID; };
    G4double GetEdep() const           			{ return fEdep; };
    G4ThreeVector GetGlobalPos() const 			{ return fGlobalPos; };
    G4ThreeVector GetLocalPos() const	  		{ return fLocalPos; };
    G4AffineTransform GetTransform() const              { return fTransform; }

    G4int GetTrackID() const				{ return fTrackID; };
    G4int GetParticle() const			        { return fParticle; };
    G4ThreeVector GetVertex() const	   	        { return fOriginPosition; };
    G4ThreeVector GetMomentum() const	                { return fOriginMomentum; };
    G4double GetTotalEnergy() const		        { return fOriginEnergy; };


   private:

    G4int fPlaneID;
    G4int fModuleID;
    G4int fSensorID;
    G4int fRowID;
    G4int fStripID;
    G4double fEdep;
    G4ThreeVector fGlobalPos;
    G4ThreeVector fLocalPos;
    G4AffineTransform fTransform;

    G4int fTrackID;
    G4int fParticle;
    G4ThreeVector fOriginPosition;
    G4ThreeVector fOriginMomentum;
    G4double fOriginEnergy;

    static const FaserDetectorConstruction* fDetectorConstruction;
};

typedef G4THitsCollection<FaserSensorHit> FaserSensorHitsCollection;

extern G4ThreadLocal G4Allocator<FaserSensorHit>* FaserSensorHitAllocator;

inline void* FaserSensorHit::operator new(size_t)
{
  if (!FaserSensorHitAllocator)
    FaserSensorHitAllocator = new G4Allocator<FaserSensorHit>;
  return (void *) FaserSensorHitAllocator->MallocSingle();
}

inline void FaserSensorHit::operator delete(void* hit)
{
  FaserSensorHitAllocator->FreeSingle((FaserSensorHit*) hit);
}

#endif
