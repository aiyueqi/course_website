#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <fstream>
#include <string>
#include "ui.h"
using namespace std;

/**
 *	定义网站所有数据的类
 *
 *	具体设定：
 *	1. 全部信息【Inf】
 *	2. 链接【Link】
 *	3. 课程【Course】
 *		教师【Teacher】
 *	4. 备忘录【Board】
 *
 *	提供功能：
 *	1. Link部分
 *		get(string)：从HTML字符串中提取一份Link信息
 *		put(ostream&)：将一份Link信息输出成一行HTML字符串
 *		static puttitle(ostream& =cout)：输出在box中的表格标题
 *		putcontent(ostream& =cout)：输出在box中的表格内容
 *	2-. Teacher部分
 *		putcontent(bool, ostream& =cout)：输出在box中的表格内容（根据bool判断是助教还是教师）
 *	2. Course部分
 *		get(string, string)：从HTML字符串和JS字符串中提取一份Course信息
 *		put(ostream&, string="HTML")：将一份Course信息输出成一行HTML字符串或一行JS字符串
 *		static puttitle(ostream& =cout)：输出在box中的表格标题
 *		putcontent(ostream& =cout)：输出在box中的表格内容
 *	3. Board部分
 *		暂无
 *	4. Inf部分
 *		string addLink(Link)：添加Link信息
 *		string delLink(string)：删除Link信息
 *		string addCourse(Course)：添加Course信息
 *		string delCourse(string)：删除Course信息
 *		void LinkBox()
 *		void CourseBox()
 *
 */

struct Link
{
	string name;
	string link;
	static void puttitle(ostream& out=cout)
	{
		boxhead(out);
		out<<"    name                link";
		boxtail(out);
	}
	void putcontent(ostream& out=cout)
	{
		boxhead(out);
		out<<"    "<<name; for(int j=name.size()/3*2;j!=20;++j) out.put(' ');
		out<<link;
		boxtail(out);
	}
};
struct Teacher
{
	string name;
	string email;
	string phone;
	string office;
	string worktime;
	void putcontent(bool type, ostream& out=cout)
	{
		out<<name<<", "<<email<<", "<<phone;
		if(type) out<<", "<<office<<", "<<worktime;
	}
};
struct Homework
{
	string content;
};
struct Score
{
	string title;
	string content;
};
struct Course
{
	static const int maxta = 2;
	static const int maxbook = 4;
	static const int maxscore = 5;
	string name;
	string var;
	string student;
	Teacher teachers[1+maxta];
	Score score[maxscore];
	string book[maxbook];
	string link;
	Homework homework;
	string other;
	static void puttitle(ostream& out=cout)
	{
		boxhead(out);
		out<<"    name                teacher";
		boxtail(out);
	}
	void putcontent(ostream& out=cout)
	{
		boxhead(out); out<<"    "<<name<<"("<<student<<")"; for(int j=name.size()/3*2+2+student.size();j!=20;++j) out.put(' ');
		teachers[0].putcontent(true,out); boxtail(out);
	}
};
struct Board
{
	static const int maxcontent = 8;
	string motto;
	string content[maxcontent];
	void putcontent(ostream& out=cout)
	{
		boxhead(out); out<<"    座右铭："<<motto; boxtail(out);
		boxendl(out);
		for(int i=0;i!=maxcontent;++i) { boxhead(out); out<<"    第"<<(i+1)<<"条备忘："<<content[i]; boxtail(out); }
	}
};
struct Inf
{
	static const int max_link = 10;
	static const int max_course = 10;
	int numL, numC;
	Link L[max_link];
	Course C[max_course];
	Board B;

public:
	Inf(): numL(0), numC(0) {}
	string addLink(Link x)
	{
		if(numL==max_link) return "数量已满，无法添加"; // 应当于尝试添加之前判断，避免无意义的输入
		L[numL++]=x; return "添加成功";
	}
	string delLink(string name)
	{
		for(int i=0;i!=numL;++i)
			if(L[i].name==name)
			{
				for(int j=i;j<numL-1;++j) L[j]=L[j+1];
				--numL;
				return "删除成功";
			}
		return "你要删除的链接不存在 -.-||";
	}
	string addCourse(Course x)
	{
		if(numC==max_course) return "数量已满，无法添加"; // 应当于尝试添加之前判断，避免无意义的输入
		C[numC++]=x; return "添加成功";
	}
	string delCourse(string name)
	{
		for(int i=0;i!=numC;++i)
			if(C[i].name==name)
			{
				for(int j=i;j<numC-1;++j) C[j]=C[j+1];
				--numC;
				return "删除成功";
			}
		return "你要删除的课程不存在 -.-||";
	}
	bool findCourse(Course& x, string name)
	{
		for(int i=0;i!=numC;++i)
			if(C[i].name==name)
			{
				x = C[i];
				return true;
			}
		return false;
	}
	string setCourse(Course& x)
	{
		for(int i=0;i!=numC;++i)
			if(C[i].name==x.name)
			{
				C[i] = x;
				return "修改成功";
			}
		return "修改失败……我勒个去，出bug了！";
	}
	void getBoard(Board& x)
	{
		x = B;
	}
	string setBoard(Board& x)
	{
		B = x;
		return "修改成功";
		return "修改失败……我勒个去，出bug了！";
	}

	string LinkBox()
	{
		ostringstream os;
		cutbox(os);
		boxendl(os); Link::puttitle(os);
		for(int i=0;i!=numL;++i) L[i].putcontent(os);
		boxendl(os);
		cutbox(os);
		os<<endl;
		return os.str();
	}
	string CourseBox()
	{
		ostringstream os;
		cutbox(os);
		boxendl(os); Course::puttitle(os);
		for(int i=0;i!=numC;++i) C[i].putcontent(os);
		boxendl(os);
		cutbox(os);
		os<<endl;
		return os.str();
	}
	string BoardBox()
	{
		ostringstream os;
		cutbox(os);
		boxendl(os);
		B.putcontent(os);
		boxendl(os);
		cutbox(os);
		os<<endl;
		return os.str();
	}
};

#endif