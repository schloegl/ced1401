#include <stdio.h>
#include <stdlib.h>

#include "use1401.h"

int main() {
	int ret=0;
	short status; 
	int k,h;

	ret = U14InitLib();
	fprintf(stdout,"%s (line %i) %s: U14InitLib returns 0x%08x MAX1401=%i\n",__FILE__,__LINE__,__func__,ret,MAX1401);

	for (k=1; k<=MAX1401; k++) {
		status = U14Open1401(k);
		fprintf(stdout,"%s (line %i) %s:0x%08x=U14OPEN(%i) \n",__FILE__,__LINE__,__func__,status,k);
		status = U14StateOf1401(k);
		fprintf(stdout,"%s (line %i) %s: 0x%08x=U14STATUS(%i)\n",__FILE__,__LINE__,__func__,status,k);
		status = U14Close1401(k);
		fprintf(stdout,"%s (line %i) %s: 0x%08x=U14CLOSE(%i)\n",__FILE__,__LINE__,__func__,status,k);
	}

	for (k=0; k<MAX1401; k++) {
		status = U14Open1401(k);
		fprintf(stdout,"%s (line %i) %s: Open1401(%i) returned 0x%x\n",__FILE__,__LINE__,__func__,k,status);	
		fprintf(stdout,"%s (line %i) %s: 0x%08x=DriverVersion(%i)\n",__FILE__,__LINE__,__func__,GetDriverVersion(k),k);
	}

	for (h=0; h<MAX1401; h++) {
		fprintf(stdout,"#0x%x handle: %i Type: %i Driver %i RetCode 0x%x DriverType %i\n",k+1,aHand1401[h],asType1401[h],alDriverVersion[h],asLastRetCode[h],asDriverType[h]);	
	}

	U14CloseAll();
	return ret;
}

