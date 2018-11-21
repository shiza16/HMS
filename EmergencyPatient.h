#ifndef EMERGENCYPATIENT_H
#define EMERGENCYPATIENT_H

#include "Patient.h"

class EmergencyPatient : public Patient
{
	public:
		EmergencyPatient();
		void setTitle();
		~EmergencyPatient();
		friend istream& operator >>(istream& input,EmergencyPatient &E);
		friend ostream& operator <<(ostream& output,EmergencyPatient &E);
	protected:
};

#endif
