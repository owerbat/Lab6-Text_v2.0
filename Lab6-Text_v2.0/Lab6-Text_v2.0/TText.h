#pragma once
#include <iostream>
#include <stack>
#include <fstream>
#include "FontColor.h"

using namespace std;
class TLink;
class TText;

struct TMem {
	TLink *pFirst;
	TLink *pFree;
	TLink *pLast;
};

class TLink {
public:
	char str[80];
	TLink *pNext, *pDown;
	bool isFree;
	static TMem mem;

	TLink(char *_str = NULL, TLink *pN = NULL, TLink *pD = NULL);
	~TLink() {}

	void *operator new(size_t s);
	void operator delete(void *p);

	static void InitMem(size_t s);
	static void MemClear(TText &txt);

	static void PrintFree();
	void SetStr(char *_str = "\0");
};





class TText {
	TLink *pFirst, *pCurr;
	stack<TLink *> st;
	int level;
public:
	TText() {}
	TText(TLink *first);

	//TText operator=(TText &t);   // не закончено

	TLink GetCurr();
	void SetCurrFalse();

	void GoNextLink();
	void GoDownLink();
	void GoPrevLink();

	void InsNextLine(char *s);
	void InsNextSection(char *s);
	void InsDownLine(char *s);
	void InsDownSection(char *s);

	void DelNext();
	void DelDown();

	char *GetLine();
	void SetLine(char *s);

	TLink *ReadRec(ifstream& file);
	void Read(char *fn);

	void PrintText(TLink *tmp);
	void Print();

	void SaveText(TLink *tmp, ofstream& f);
	void Save(char *name);

	TLink *CopyRec(TLink *first);
	TLink *Copy();

	void Reset();
	bool IsEnd();
	void GoNext();
};