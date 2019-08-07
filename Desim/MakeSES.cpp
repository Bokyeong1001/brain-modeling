#pragma once
#include "stdafx.h"
#include "Tglobal.h"
#include "Entstr.h"

#include "genr.h"
#include "Transd.h"
#include "Process.h"

ENTSTR * EFP;
void MakeSES(void)
{	

	EFP = new ENTSTR("ef-b");
	EFP->AddItem(new DIGRAPH("brain"));
	EFP->AddItem(new DIGRAPH("ef"));

	EFP->AddCouple("ef", "brain", "OUT", "in");
	EFP->AddCouple("brain", "ef", "out", "IN");

	EFP->SetCurrentItem("brain");
	EFP->AddItem(new Process("thalamus"));
	EFP->AddItem(new Process("amygdala"));
	EFP->AddItem(new Process("hyperthalamus"));

	EFP->AddCouple("brain", "thalamus", "in", "in");
	EFP->AddCouple("thalamus", "amygdala", "out", "in");
	EFP->AddCouple("amygdala", "hyperthalamus", "out", "in");
	EFP->AddCouple("hyperthalamus", "Process", "out", "out");          

	EFP->SetCurrentItem("ef");
	EFP->AddItem(new GENR("genr"));
	EFP->AddItem(new Transd("transd"));
	EFP->AddCouple("ef", "transd", "IN", "solved");
	EFP->AddCouple("transd", "genr", "out", "stop");

	EFP->AddCouple("genr", "ef", "out", "OUT");            
	EFP->AddCouple("genr", "transd", "out", "arriv");
}
void StartSimulation()
{
	EFP->Restart();
}