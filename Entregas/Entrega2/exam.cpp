//
//  Exam.cpp
//
//  Created by Mauricio G. Coello on 29/3/17.
//  Copyright © 2017 Mauricio G. Coello. All rights reserved.
//
//	Second term exam
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Printer;
class Document
{
protected:
	string content;
public:
	template <class T>
	static T* getInstance()
	{
		if (T::instance == NULL)
		{
			T();
			T* w = new T();
		}
		return T::instance;
	}
	string getContent() {
		return content;
	}
	void printOn(Printer* p);
};
class SimpleText : public Document {
protected:
	friend class Document;
	SimpleText()
	{
		instance = this;
		content = "Im a Simple Text Document";
	}
	static SimpleText* instance;
};
class FormattedText : public Document {
protected:
	friend class Document;
	FormattedText()
	{
		instance = this;
		content = "Im a Formatted Text Document";
	}
	static FormattedText* instance;
};
class Image : public Document {
protected:
	friend class Document;
	Image()
	{
		instance = this;
		content = "Im an Image";
	}
	static Image* instance;
};
class Printer
{
protected:
	string deviceType;
public:
	template <class T>
	static T* getInstance()
	{
		if (T::instance == NULL)
		{
			T();
			T* w = new T();
		}
		return T::instance;
	}
	void sendToPrinter(Document* d)
	{
		cout << d->getContent() + " printed by a " + deviceType << endl;
	}
};
class LaserPrinter : public Printer {
protected:
	friend class Printer;
	LaserPrinter()
	{
		instance = this;
		deviceType = "Laser Printer";
	}
	static LaserPrinter* instance;
};
class InkjetPrinter : public Printer {
protected:
	friend class Printer;
	InkjetPrinter()
	{
		instance = this;
		deviceType = "Inkjet Printer";
	}
	static InkjetPrinter* instance;
};
class PDFPrinter : public Printer {
protected:
	friend class Printer;
	PDFPrinter()
	{
		instance = this;
		deviceType = "PDF Printer";
	}
	static PDFPrinter* instance;
};
class PostscriptPrinter : public Printer {
protected:
	friend class Printer;
	PostscriptPrinter()
	{
		instance = this;
		deviceType = "Postscript Printer";
	}
	static PostscriptPrinter* instance;
};

void Document::printOn(Printer* p)
{
	p->sendToPrinter(this);
}

//subclass definition of second step
class PortablePrinter : public Printer {
protected:
	friend class Printer;
	PortablePrinter()
	{
		instance = this;
		deviceType = "Portable Printer";
	}
	static PortablePrinter* instance;
};
class PresentationCard : public Document {
protected:
	friend class Document;
	PresentationCard()
	{
		instance = this;
		content = "Im a Presentation card";
	}
	static PresentationCard* instance;
};

SimpleText* SimpleText::instance = 0;
FormattedText* FormattedText::instance = 0;
Image* Image::instance = 0;
LaserPrinter* LaserPrinter::instance = 0;
InkjetPrinter* InkjetPrinter::instance = 0;
PDFPrinter* PDFPrinter::instance = 0;
PostscriptPrinter* PostscriptPrinter::instance = 0;

//Second step
PortablePrinter* PortablePrinter::instance = 0;
PresentationCard* PresentationCard::instance = 0;


int main()
{
	//Installs printers of first step
	vector<Printer*> deviceManager;
	deviceManager.push_back(Printer::getInstance<LaserPrinter>());
	deviceManager.push_back(Printer::getInstance<InkjetPrinter>());
	deviceManager.push_back(Printer::getInstance<PDFPrinter>());
	deviceManager.push_back(Printer::getInstance<PostscriptPrinter>());

	//Creates documents of first steps=
	vector<Document*> printQueue;
	printQueue.push_back(Document::getInstance<SimpleText>());
	printQueue.push_back(Document::getInstance<FormattedText>());
	printQueue.push_back(Document::getInstance<Image>());

	//Adds printer and document of second step
	deviceManager.push_back(Printer::getInstance<PortablePrinter>());
	printQueue.push_back(Document::getInstance<PresentationCard>());


	for (int i = 0; i < printQueue.size(); i++)
	{
		for (int j = 0; j < deviceManager.size(); j++)
		{
			printQueue.at(i)->printOn(deviceManager.at(j));
		}
	}
}

