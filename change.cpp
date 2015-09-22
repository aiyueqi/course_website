#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ui.h"
#include "data.h"
#include "io.h"
using namespace std;

/**
 *	主程序
 *
 *	主界面的逻辑和外观设计
 *
 *	包含：
 *	1. ui.h		外观设计所需的函数
 *	2. data.h	数据结构
 *	3. io.h		对 课程网站源代码 的 输入输出
 *
 *	做了什么：
 *	1. 定义了 data.h 中的 Inf类 实例 A
 *	2. 利用 io.h 中的 Input(Inf&) 从 课程网站源代码 中读入 Inf信息
 *	3. 在屏幕上展开主界面，供用户使用，直至用户正常退出
 *	4. 以当前 Inf类 实例A 为准，利用 io.h 中的 Output(const Inf&) 生成新的 课程网站源代码
 *
 */

//----------------------------------------------------------------------------------------------------//
//                                        代码框架                                                     //
//----------------------------------------------------------------------------------------------------//

Inf A; // 信息
string cover; // 封面

int getLine(istream& in, string& str)
{
	getline(in,str);
	if(str=="-stop") return 1;
	if(str=="~") return -1;
	return 0;
}

string addLink();
string delLink();
void Hello1(string reply); // 链接部分 界面
string Work1(); // 链接部分【已完成】

string addCourse();
string delCourse();
string addTeachers();
string addScores();
string addBooks();
string addTheLink();
string addHomework();
string addOther();
void Hello2(string reply); // 课程部分 界面
string Work2(); // 课程部分【将要添加很多信息】

string Work3(); // 备忘录【未开始】

void Hi();
void Hello(string reply); // 主界面
void Work();
void Bye();

int main()
{
	Input(A, cover);

	Hi();
	Work();
	Bye();

	Output(A);
	return 0;
}

//----------------------------------------------------------------------------------------------------//
//                                        链接部分                                                     //
//----------------------------------------------------------------------------------------------------//
string addLink()
{
	Link x;
	ostringstream os;

	PUT. setHead("添加链接"). setNotice(A.LinkBox());

	PUT. addBody("告我链接名字"). print();
	if(getLine(cin,x.name)) { PUT.clear(); return "中断操作"; }
	os<<"name="<<x.name;

	PUT. setBody("告我链接地址"). setBottom(os.str()). print();
	if(getLine(cin,x.link)) { PUT.clear(); return "中断操作"; }

	PUT. clear();
	return A.addLink(x);
}
string delLink()
{
	string name;

	PUT. setHead("删除链接"). setNotice(A.LinkBox());

	PUT. addBody("告我链接名字"). print();
	if(getLine(cin,name)) { PUT.clear(); return "中断操作"; }

	PUT. clear();
	return A.delLink(name);
}
void Hello1(string reply)
{
	PUT. setHead("链接 部分"). setNotice(A.LinkBox());

	PUT. addBody("a. 添加"). addBody("d. 删除"). setBottom(reply). print();

	PUT. clear();
}
string Work1()
{
	string order;
	string reply = "";
	while(true)
	{
		Hello1(reply); getline(cin,order);
		if(order=="a") { reply = addLink(); continue; }
		if(order=="d") { reply = delLink(); continue; }
		if(order=="") break;
		reply = "输入不符合要求 -.-||";
	}
	return "从链接部分返回主界面";
}

//----------------------------------------------------------------------------------------------------//
//                                        课程部分                                                     //
//----------------------------------------------------------------------------------------------------//
string addCourse()
{
	Course x;
	ostringstream os;

	PUT. setHead("添加课程"). setNotice(A.CourseBox());

	PUT. addBody("告我课程名字"). print();
	if(getLine(cin,x.name)) { PUT.clear(); return "中断操作"; }
	os<<"课程："<<x.name;

	PUT. setBody("告我课程变量名（用于js）"). setBottom(os.str()). print();
	if(getLine(cin,x.var)) { PUT.clear(); return "中断操作"; }
	os<<", "<<x.var;

	PUT. setBody("告我课程学生（boy/girl）"). setBottom(os.str()). print();
	if(getLine(cin,x.student)) { PUT.clear(); return "中断操作"; }
	os<<", "<<x.student;

	PUT. clear();
	return A.addCourse(x);
}
string delCourse()
{
	string name;

	PUT. setHead("删除课程"). setNotice(A.CourseBox());

	PUT. addBody("告我课程名字"). print();
	if(getLine(cin,name)) { PUT.clear(); return "中断操作"; }

	PUT. clear();
	return A.delCourse(name);
}
string addTeachers()
{
	string name;
	Course x;
	ostringstream os;

	PUT. setHead("设置教师信息"). setNotice(A.CourseBox());

	PUT. setBody("告我课程名字"). print();
	if(getLine(cin, name)) { PUT.clear(); return "中断操作"; }
	os<<"课程："<<name<<endl;

	if(!A.findCourse(x, name)) return "你找的课程不存在 -.-||";

	Teacher& now = x.teachers[0];

	PUT. setBody("告我教师名字"). setBottom(os.str()). print();
	if(getLine(cin,now.name)) { PUT.clear(); return "中断操作"; }
	os<<"\t教师："<<now.name;

	PUT. setBody("告我教师邮箱"). setBottom(os.str()). print();
	if(getLine(cin,now.email)) { PUT.clear(); return "中断操作"; }
	os<<", "<<now.email;

	PUT. setBody("告我教师电话"). setBottom(os.str()). print();
	if(getLine(cin,now.phone)) { PUT.clear(); return "中断操作"; }
	os<<", "<<now.phone;

	PUT. setBody("告我教师办公室"). setBottom(os.str()). print();
	if(getLine(cin,now.office)) { PUT.clear(); return "中断操作"; }
	os<<", "<<now.office;

	PUT. setBody("告我教师办公时间"). setBottom(os.str()). print();
	if(getLine(cin,now.worktime)) { PUT.clear(); return "中断操作"; }
	os<<", "<<now.worktime<<endl;

	for(int i=1;i<=Course::maxta;++i)
	{
		Teacher& now = x.teachers[i];

		PUT. setBody("告我助教名字"). setBottom(os.str()). print();
		if(getLine(cin,now.name)) { PUT.clear(); return "中断操作"; }
		os<<"\t助教"<<i<<"号："<<now.name;

		PUT. setBody("告我助教邮箱"). setBottom(os.str()). print();
		if(getLine(cin,now.email)) { PUT.clear(); return "中断操作"; }
		os<<", "<<now.email;

		PUT. setBody("告我助教电话"). setBottom(os.str()). print();
		if(getLine(cin,now.phone)) { PUT.clear(); return "中断操作"; }
		os<<", "<<now.phone<<endl;
	}

	PUT. clear();
	return A.setCourse(x);
}
string addScores()
{
	string name;
	Course x;
	ostringstream os;

	PUT. setHead("设置分数信息"). setNotice(A.CourseBox());

	PUT. setBody("告我课程名字"). print();
	if(getLine(cin, name)) { PUT.clear(); return "中断操作"; }
	os<<"课程："<<name<<endl;

	if(!A.findCourse(x, name)) return "你找的课程不存在 -.-||";

	for(int i=0;i!=Course::maxscore;++i)
	{
		PUT. setBody("告我分数项标题"). setBottom(os.str()). print();
		if(getLine(cin, x.score[i].title)) { PUT.clear(); return "中断操作"; }
		os<<x.score[i].title<<"：";

		PUT. setBody("告我分数项内容"). setBottom(os.str()). print();
		if(getLine(cin, x.score[i].content)) { PUT.clear(); return "中断操作"; }
		os<<x.score[i].content<<endl;
	}
	
	PUT. clear();
	return A.setCourse(x);
}
string addBooks()
{
	string name;
	Course x;
	ostringstream os;

	PUT. setHead("设置书籍信息"). setNotice(A.CourseBox());

	PUT. setBody("告我课程名字"). print();
	if(getLine(cin, name)) { PUT.clear(); return "中断操作"; }
	os<<"课程："<<name<<endl;

	if(!A.findCourse(x, name)) return "你找的课程不存在 -.-||";

	PUT. setBody("告我第一本书"). setBottom(os.str()). print();
	if(getLine(cin, x.book[0])) { PUT.clear(); return "中断操作"; }
	os<<"第一本书："<<x.book[0]<<endl;

	PUT. setBody("告我第二本书"). setBottom(os.str()). print();
	if(getLine(cin, x.book[1])) { PUT.clear(); return "中断操作"; }
	os<<"第二本书："<<x.book[1]<<endl;

	PUT. setBody("告我第三本书"). setBottom(os.str()). print();
	if(getLine(cin, x.book[2])) { PUT.clear(); return "中断操作"; }
	os<<"第三本书："<<x.book[2]<<endl;

	PUT. setBody("告我第四本书"). setBottom(os.str()). print();
	if(getLine(cin, x.book[3])) { PUT.clear(); return "中断操作"; }
	//os<<"第四本书："<<x.book[3]<<endl;

	PUT. clear();
	return A.setCourse(x);
}
string addTheLink()
{
	string name;
	Course x;
	ostringstream os;

	PUT. setHead("设置链接信息"). setNotice(A.CourseBox());

	PUT. setBody("告我课程名字"). print();
	if(getLine(cin, name)) { PUT.clear(); return "中断操作"; }
	os<<"课程："<<name<<endl;

	if(!A.findCourse(x, name)) return "你找的课程不存在 -.-||";

	PUT. setBody("告我完整链接地址"). setBottom(os.str()). print();
	if(getLine(cin, x.link)) { PUT.clear(); return "中断操作"; }
	//os<<"完整链接地址："<<x.link<<endl;

	PUT. clear();
	return A.setCourse(x);
}
string addHomework()
{
	string name;
	Course x;
	ostringstream os;

	PUT. setHead("设置作业信息"). setNotice(A.CourseBox());

	PUT. setBody("告我课程名字"). print();
	if(getLine(cin, name)) { PUT.clear(); return "中断操作"; }
	os<<"课程："<<name<<endl;

	if(!A.findCourse(x, name)) return "你找的课程不存在 -.-||";

	PUT. setBody("告我作业"). setBottom(os.str()). print();
	if(getLine(cin, x.homework.content)) { PUT.clear(); return "中断操作"; }

	PUT. clear();
	return A.setCourse(x);
}
string addOther()
{
	string name;
	Course x;
	ostringstream os;

	PUT. setHead("设置其他信息"). setNotice(A.CourseBox());

	PUT. setBody("告我课程名字"). print();
	if(getLine(cin, name)) { PUT.clear(); return "中断操作"; }
	os<<"课程："<<name<<endl;

	if(!A.findCourse(x, name)) return "你找的课程不存在 -.-||";

	PUT. setBody("告我其他课程信息"). setBottom(os.str()). print();
	if(getLine(cin, x.other)) { PUT.clear(); return "中断操作"; }
	//os<<"其他课程信息："<<x.other<<endl;

	PUT. clear();
	return A.setCourse(x);
}
void Hello2(string reply)
{
	PUT. setHead("课程 部分"). setNotice(A.CourseBox());

	PUT. addBody("a. 添加"). addBody("d. 删除"). setBottom(reply);

	PUT. addBody("at. 设置教师信息");
	PUT. addBody("as. 设置分数信息");
	PUT. addBody("ab. 设置书籍信息");
	PUT. addBody("al. 设置链接信息");
	PUT. addBody("ah. 设置作业信息");
	PUT. addBody("ao. 设置其他信息");

	PUT. print(). clear();
}
string Work2()
{
	string order;
	string reply = "";
	while(true)
	{
		Hello2(reply); getline(cin,order);
		if(order=="a") { reply = addCourse(); continue; }
		if(order=="d") { reply = delCourse(); continue; }
		if(order=="at") { reply = addTeachers(); continue; }
		if(order=="as") { reply = addScores(); continue; }
		if(order=="ab") { reply = addBooks(); continue; }
		if(order=="al") { reply = addTheLink(); continue; }
		if(order=="ah") { reply = addHomework(); continue; }
		if(order=="ao") { reply = addOther(); continue; }
		if(order=="") break;
		reply = "输入不符合要求 -.-||";
	}
	return "从课程部分返回主界面";
}

//----------------------------------------------------------------------------------------------------//
//                                        备忘录                                                       //
//----------------------------------------------------------------------------------------------------//
string addMotto()
{
	Board x;
	ostringstream os;

	PUT. setHead("设置座右铭信息"). setNotice(A.BoardBox());

	A.getBoard(x);

	PUT. setBody("请输入你的座右铭内容"). print();
	if(getLine(cin, x.motto)) { PUT.clear(); return "中断操作"; }

	PUT. clear();
	return A.setBoard(x);
}
string addContent()
{
	int p;
	Board x;
	string order;
	ostringstream os;

	PUT. setHead("设置备忘录信息"). setNotice(A.BoardBox());

	A.getBoard(x);

	PUT. setBody("告我第一条备忘"). setBottom(os.str()). print();
	p=getLine(cin, order);
	if(p==1) { PUT.clear(); return "中断操作"; }
	if(p==0) x.content[0]=order;
	os<<"第一条备忘："<<x.content[0]<<endl;

	PUT. setBody("告我第二条备忘"). setBottom(os.str()). print();
	p=getLine(cin, order);
	if(p==1) { PUT.clear(); return "中断操作"; }
	if(p==0) x.content[1]=order;
	os<<"第二条备忘："<<x.content[1]<<endl;

	PUT. setBody("告我第三条备忘"). setBottom(os.str()). print();
	p=getLine(cin, order);
	if(p==1) { PUT.clear(); return "中断操作"; }
	if(p==0) x.content[2]=order;
	os<<"第三条备忘："<<x.content[2]<<endl;

	PUT. setBody("告我第四条备忘"). setBottom(os.str()). print();
	p=getLine(cin, order);
	if(p==1) { PUT.clear(); return "中断操作"; }
	if(p==0) x.content[3]=order;
	os<<"第四条备忘："<<x.content[3]<<endl;

	PUT. setBody("告我第五条备忘"). setBottom(os.str()). print();
	p=getLine(cin, order);
	if(p==1) { PUT.clear(); return "中断操作"; }
	if(p==0) x.content[4]=order;
	os<<"第五条备忘："<<x.content[4]<<endl;

	PUT. setBody("告我第六条备忘"). setBottom(os.str()). print();
	p=getLine(cin, order);
	if(p==1) { PUT.clear(); return "中断操作"; }
	if(p==0) x.content[5]=order;
	os<<"第六条备忘："<<x.content[5]<<endl;

	PUT. setBody("告我第七条备忘"). setBottom(os.str()). print();
	p=getLine(cin, order);
	if(p==1) { PUT.clear(); return "中断操作"; }
	if(p==0) x.content[6]=order;
	os<<"第七条备忘："<<x.content[6]<<endl;

	PUT. setBody("告我第八条备忘"). setBottom(os.str()). print();
	p=getLine(cin, order);
	if(p==1) { PUT.clear(); return "中断操作"; }
	if(p==0) x.content[7]=order;
	os<<"第八条备忘："<<x.content[7]<<endl;


	PUT. clear();
	return A.setBoard(x);
}
void Hello3(string reply)
{
	PUT. setHead("备忘录 部分"). setNotice(A.BoardBox());

	PUT. addBody("am. 设置座右铭信息");
	PUT. addBody("ac. 设置备忘录信息");

	PUT. print(). clear();
}
string Work3()
{
	string order;
	string reply = "";
	while(true)
	{
		Hello3(reply); getline(cin,order);
		if(order=="am") { reply = addMotto(); continue; }
		if(order=="ac") { reply = addContent(); continue; }
		if(order=="") break;
		reply = "输入不符合要求 -.-||";
	}
	return "从备忘录返回主界面";
}

//----------------------------------------------------------------------------------------------------//
//                                        主界面                                                       //
//----------------------------------------------------------------------------------------------------//
void Hi()
{
	string god; // god专用于吃掉本行所有输入

	PUT. setImage(cover);

	PUT. setBottom("找不到更好的图片了，而且jp2a算法太差 -.-||"). print();

	PUT. clear();

	getline(cin,god);
}
void Hello(string reply)
{
	PUT. setHead("change.cpp");

	PUT. addBody("1. 链接"). addBody("2. 课程"). addBody("3. 备忘录"). setBottom(reply). print();

	PUT. clear();
}
void Work()
{
	string order;
	string reply = "";
	while(true)
	{
		Hello(reply); getline(cin,order);
		if(order=="1") { reply = Work1(); continue; }
		if(order=="2") { reply = Work2(); continue; }
		if(order=="3") { reply = Work3(); continue; }
		if(order=="") break;
		reply = "输入不符合要求 -.-||";
	}
}
void Bye()
{
	PUT. setHead("change.cpp");

	PUT. addBody("Bye～！"). setBottom("你已退出 -.-||"). print();

	PUT. clear();
}