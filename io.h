#ifndef IO_H
#define IO_H

#include <iostream>
#include <fstream>
#include "data.h"
using namespace std;

#define HTMLurl "website/index.html"
#define JSurl "website/js/index.js"
#define INFurl "inf.txt"
#define COVERurl "cover.txt"

/**
 *	解决所有文件输入输出
 *
 *	具体设定：
 *	1. 输入【Input()】：直接调用，可读入所需数据，同时保存其余源代码供输出恢复文件
 *	2. 输出【Output()】：直接调用，可输出修改后的数据，同时恢复其余源代码 !! 还未改为const
 *
 *	文件解析：
 *	1. HTML【index.html】
 *		Part0
 *		Links
 *		Part1
 *		Courses
 *		Part2
 *	2. JS【index.js】
 *		Part0
 *		Courses
 *		Part1
 *
 */

void Input(Inf& A, string& c)
{
	ifstream inf(INFurl);
	ifstream cover(COVERurl);

	string a;

// Cover

	while(getline(cover,a)) c+=a;

// Link

	getline(inf, a);
	if(a!="//------------------------------读取信息 Link--------------------------------------------------")
	{
		cout<<"1 inf.txt格式错误！"<<endl;
		while(true);
	}
	inf >> A.numL;
	getline(inf, a);
	for(int i=0;i!=A.numL;++i)
	{
		getline(inf, A.L[i].name);
		getline(inf, A.L[i].link);
	}

// Course

	getline(inf, a);
	if(a!="//------------------------------读取信息 Course--------------------------------------------------")
	{
		cout<<"2 inf.txt格式错误！"<<endl;
		while(true);
	}
	inf >> A.numC;
	getline(inf, a);
	for(int i=0;i!=A.numC;++i)
	{
		getline(inf, A.C[i].name);
		getline(inf, A.C[i].var);
		getline(inf, A.C[i].student);
		getline(inf, A.C[i].teachers[0].name);
		getline(inf, A.C[i].teachers[0].email);
		getline(inf, A.C[i].teachers[0].phone);
		getline(inf, A.C[i].teachers[0].office);
		getline(inf, A.C[i].teachers[0].worktime);
		getline(inf, A.C[i].teachers[1].name);
		getline(inf, A.C[i].teachers[1].email);
		getline(inf, A.C[i].teachers[1].phone);
		getline(inf, A.C[i].teachers[2].name);
		getline(inf, A.C[i].teachers[2].email);
		getline(inf, A.C[i].teachers[2].phone);
		getline(inf, A.C[i].score[0].title);
		getline(inf, A.C[i].score[0].content);
		getline(inf, A.C[i].score[1].title);
		getline(inf, A.C[i].score[1].content);
		getline(inf, A.C[i].score[2].title);
		getline(inf, A.C[i].score[2].content);
		getline(inf, A.C[i].score[3].title);
		getline(inf, A.C[i].score[3].content);
		getline(inf, A.C[i].score[4].title);
		getline(inf, A.C[i].score[4].content);
		getline(inf, A.C[i].book[0]);
		getline(inf, A.C[i].book[1]);
		getline(inf, A.C[i].book[2]);
		getline(inf, A.C[i].book[3]);
		getline(inf, A.C[i].link);
		getline(inf, A.C[i].homework.content);
		getline(inf, A.C[i].other);
	}

// Board

	getline(inf, a);
	if(a!="//------------------------------读取信息 Board--------------------------------------------------")
	{
		cout<<"3 inf.txt格式错误！"<<endl;
		while(true);
	}
	getline(inf, A.B.motto);
	for(int i=0;i!=Board::maxcontent;++i) getline(inf, A.B.content[i]);

	inf.close();
	cover.close();
}

struct HTMLfile
{
	string Part[4];
	//string Links;
	//string Courses;
	//string Board;
}html_file;
struct JSfile
{
	string Part[3];
	//string Courses;
	//string Board;
}js_file;

void readIn(Inf& A)
{
	ifstream html(HTMLurl);
	ifstream js(JSurl);

	string a;

// readin HTML

	while(a!="<div id='Link'>")
	{
		getline(html, a);
		html_file.Part[0] += a + "\n";
	}

	while(a!="</div>") getline(html, a);
	html_file.Part[1] += a + "\n";
	while(a!="        <div id='course'>")
	{
		getline(html, a);
		html_file.Part[1] += a + "\n";
	}

	while(a!="        </div>") getline(html, a);
	html_file.Part[2] += a + "\n";
	while(a!="<div id='memo'>")
	{
		getline(html, a);
		html_file.Part[2] += a + "\n";
	}

	while(a!="        <p id='tag'>备忘录</p>") getline(html, a);
	html_file.Part[3] += a + "\n";
	while(getline(html, a)) html_file.Part[3] += a + "\n";

// readin JS

	while(a!="//------------------------------读取信息 Course in--------------------------------------------------")
	{
		getline(js, a);
		js_file.Part[0] += a + "\n";
	}
	while(a!="//------------------------------读取信息 Course out--------------------------------------------------") getline(js, a);
	js_file.Part[1] += a + "\n";
	while(a!="//------------------------------读取信息 备忘 in--------------------------------------------------")
	{
		getline(js, a);
		js_file.Part[1] += a + "\n";
	}
	while(a!="//------------------------------读取信息 备忘 out--------------------------------------------------") getline(js, a);
	js_file.Part[2] += a + "\n";
	while(getline(js, a)) js_file.Part[2] += a + "\n";

	html.close();
	js.close();
}

void writeOut(Inf& A)
{
	ofstream html(HTMLurl);
	ofstream js(JSurl);

// writeout HTML

	html << html_file.Part[0];
	for(int i=0;i!=A.numL;++i)
	{
		html << "        <p class='top'><a href='" << A.L[i].link;
		html << "'>" << A.L[i].name;
		html << "</a></p>" << endl;
	}
	html << html_file.Part[1];
	for(int i=0;i!=A.numC;++i)
	{
		html << "                <button onclick='show(" << A.C[i].var;
		html << ")' class='" << A.C[i].student;
		html << "' value='" << A.C[i].name;
		html << "'>" << A.C[i].name;
		html << "</button>" << endl;
	}
	html << html_file.Part[2];
	html << "        <p id='motto'>" << A.B.motto << "</p>" << endl;
	html << html_file.Part[3];
	
// writeout JSurl

	js << js_file.Part[0];
	for(int i=0;i!=A.numC;++i)
	{
		js << "var " << A.C[i].var;
		js << "=new Course('" << A.C[i].var;
		js << "', '" << A.C[i].teachers[0].name;
		js << "', '" << A.C[i].teachers[0].email;
		js << "', '" << A.C[i].teachers[0].phone;
		js << "', '" << A.C[i].teachers[0].office;
		js << "', '" << A.C[i].teachers[0].worktime;
		js << "', '" << A.C[i].teachers[1].name;
		js << "', '" << A.C[i].teachers[1].email;
		js << "', '" << A.C[i].teachers[1].phone;
		js << "', '" << A.C[i].teachers[2].name;
		js << "', '" << A.C[i].teachers[2].email;
		js << "', '" << A.C[i].teachers[2].phone;
		js << "');" << endl;
		js << A.C[i].var;
		js << ".score=new score('" << A.C[i].score[0].title;
		js << "', '" << A.C[i].score[0].content;
		js << "', '" << A.C[i].score[1].title;
		js << "', '" << A.C[i].score[1].content;
		js << "', '" << A.C[i].score[2].title;
		js << "', '" << A.C[i].score[2].content;
		js << "', '" << A.C[i].score[3].title;
		js << "', '" << A.C[i].score[3].content;
		js << "', '" << A.C[i].score[4].title;
		js << "', '" << A.C[i].score[4].content;
		js << "');" << endl;
		js << A.C[i].var;
		js << ".book=new book('" << A.C[i].book[0];
		js << "', '" << A.C[i].book[1];
		js << "', '" << A.C[i].book[2];
		js << "', '" << A.C[i].book[3];
		js << "');" << endl;
		js << A.C[i].var;
		js << ".linking='" << A.C[i].link;
		js << "';" << endl;
		js << A.C[i].var;
		js << ".homework='" << A.C[i].homework.content;
		js << "';" << endl;
		js << A.C[i].var;
		js << ".other='" << A.C[i].other;
		js << "';" << endl;
	}
	js << js_file.Part[1];
	js << "var content=new Content('" << A.B.content[0];
	js << "', '" << A.B.content[1];
	js << "', '" << A.B.content[2];
	js << "', '" << A.B.content[3];
	js << "', '" << A.B.content[4];
	js << "', '" << A.B.content[5];
	js << "', '" << A.B.content[6];
	js << "', '" << A.B.content[7];
	js << "');" << endl;
	js << js_file.Part[2];

	html.close();
	js.close();
}

void save(Inf& A)
{
	ofstream inf(INFurl);

	inf << "//------------------------------读取信息 Link--------------------------------------------------" << endl;

	inf << A.numL << endl;
	for(int i=0;i!=A.numL;++i)
	{
		inf << A.L[i].name << endl;
		inf << A.L[i].link << endl;
	}

	inf << "//------------------------------读取信息 Course--------------------------------------------------" << endl;

	inf << A.numC << endl;
	for(int i=0;i!=A.numC;++i)
	{
		inf << A.C[i].name << endl;
		inf << A.C[i].var << endl;
		inf << A.C[i].student << endl;
		inf << A.C[i].teachers[0].name << endl;
		inf << A.C[i].teachers[0].email << endl;
		inf << A.C[i].teachers[0].phone << endl;
		inf << A.C[i].teachers[0].office << endl;
		inf << A.C[i].teachers[0].worktime << endl;
		inf << A.C[i].teachers[1].name << endl;
		inf << A.C[i].teachers[1].email << endl;
		inf << A.C[i].teachers[1].phone << endl;
		inf << A.C[i].teachers[2].name << endl;
		inf << A.C[i].teachers[2].email << endl;
		inf << A.C[i].teachers[2].phone << endl;
		inf << A.C[i].score[0].title << endl;
		inf << A.C[i].score[0].content << endl;
		inf << A.C[i].score[1].title << endl;
		inf << A.C[i].score[1].content << endl;
		inf << A.C[i].score[2].title << endl;
		inf << A.C[i].score[2].content << endl;
		inf << A.C[i].score[3].title << endl;
		inf << A.C[i].score[3].content << endl;
		inf << A.C[i].score[4].title << endl;
		inf << A.C[i].score[4].content << endl;
		inf << A.C[i].book[0] << endl;
		inf << A.C[i].book[1] << endl;
		inf << A.C[i].book[2] << endl;
		inf << A.C[i].book[3] << endl;
		inf << A.C[i].link << endl;
		inf << A.C[i].homework.content << endl;
		inf << A.C[i].other << endl;
	}

	inf << "//------------------------------读取信息 Board--------------------------------------------------" << endl;

	inf << A.B.motto << endl;
	for(int i=0;i!=Board::maxcontent;++i) inf << A.B.content[i] << endl;

	inf << "//------------------------------读取信息 End--------------------------------------------------" << endl;

	inf.close();
}

void Output(Inf& A)
{
	readIn(A);
	writeOut(A);
	save(A);
}

#endif