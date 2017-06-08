#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdint>
#include <TFile.h>
#include <TTree.h>

int main(int argc, char* argv[]) {
	//////////////////////////////////////////////////////
	////		Check Input Parameters
	//////////////////////////////////////////////////////
	if (argc != 4) {
		printf("Usage: ./Main N M R\n\
				N = \n\
				M = \n\
				R = \n");
		return -1;
	}

	//////////////////////////////////////////////////////
	////		Initialize Input Parameters
	//////////////////////////////////////////////////////
	uint32_t N, M, R;
	N = atol(argv[1]);
	M = atol(argv[2]);
	R = atol(argv[3]);

	//////////////////////////////////////////////////////
	////		Get pwd for File Saving
	//////////////////////////////////////////////////////
	std::string pwd;
	char cwd[1024];
	if (getcwd(cwd,sizeof(cwd)) != NULL)
		pwd = cwd;
	else {
		printf("ERROR: Could not find cwd!\n");
		return -1;
	}   

	//////////////////////////////////////////////////////
	////		ROOT Setup
	//////////////////////////////////////////////////////
	std::string outPref, outfileName;
	outPref = pwd + "/raw_root/";
	outfileName = outPref + "raw_Main.root";

	//	Create file
	TFile *outFile;
	outFile = TFile::Open(outfileName.c_str(), "RECREATE");

	//	Create tree (run)
	std::string rT_id   = "rawMain";
	std::string rT_name = "Raw Main";
	TTree *rawT = new TTree(rT_id.c_str(),rT_name.c_str());

	//	Create the ROOT stuff
	
	//////////////////////////////////////////////////////
	////		Do the ROOT Stuff
	//////////////////////////////////////////////////////
	

	//////////////////////////////////////////////////////
	////		Finalize ROOT
	//////////////////////////////////////////////////////
	rawT->Write();
	outFile->Close();

	return 0;
}
