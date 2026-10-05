#pragma once

// modified Oct 4, 2026 2:00 GMT +3

// Idea from Qt3, sorry Trolltech :))
struct SharedData
{
    SharedData()		             { Owners = 1; }
    void Reference()		         { Owners++; }
    bool DeReference()	             { return !--Owners; }
	int GetOwnerNum() const          { return Owners; }
private:
    int Owners;
};