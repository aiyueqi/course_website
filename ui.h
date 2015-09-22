#ifndef UI_H
#define UI_H

#include <iostream>
using namespace std;

/**
 *	供命令行输出所使用的ui库
 *
 *	具体设定：
 *
 *	1. 屏幕规格：建议采用Ubuntu下全屏
 *		宽度【WIDTH】：ubuntu下全屏为144，小屏则为80
 *		高度【HEIGHT】：ubuntu下全屏为41，小屏则为24
 *
 *	2. 输出方框：建议先输出上边和一空行，再输出内容，最后输出一空行和下边
 *		cutbox(ostream& =cout)：上下两条边
 *		boxhead(ostream& =cout)：一行的开头
 *		boxtail(ostream& =cout)：一行的结尾（由于中文存在，无法计算宽度，结尾即方框右侧不封口）
 *		boxendl(ostream& =cout)：换行
 *
 *	3. 全屏输出
 *		begin()：开启新的一页
 *		end()：结束本页
 *		put(int, string)：从第int行开始，输出string
 *		
 *		由于中文存在，无法算出(i,j)坐标，只能记录行数，并且假设：
 *		→ 每次输出均从行首开始
 *		→ 每次输出仅占一行，或者多行且仅有'\n'换行，不存在中间无换行的占位超过WIDTH的连续字符
 *
 */

const int WIDTH = 144;
const int HEIGHT = 41;

//----------------------------------------------------------------------------------------------------//
//                                        Box输出                                                     //
//----------------------------------------------------------------------------------------------------//

inline void putcs(char x,int n=1,ostream& out=cout) { for(int i=0;i<n;++i) out.put(x); }

inline void cutbox(ostream& out=cout) { putcs(' ',8,out); putcs('+',1,out); putcs('-',WIDTH-18,out); putcs('+',1,out); putcs('\n',1,out); }
inline void boxhead(ostream& out=cout) { putcs(' ',8,out); putcs('|',1,out); }
inline void boxtail(ostream& out=cout) { putcs('\n',1,out); }
inline void boxendl(ostream& out=cout) { boxhead(out); boxtail(out); }

//----------------------------------------------------------------------------------------------------//
//                                        全屏输出                                                     //
//----------------------------------------------------------------------------------------------------//

class PUTScreen
{
	static const int top = 3; // 标题位置
	static const int DIS = 3; // 标题Box间距
	static const int dis = 2; // Box正文间距
	static const int bot = 36; // reply消息位置

	int at; // 当前处于哪一行

	void moveto(int i) { putcs('\n',i-at); at=i; }
	void movewith(string content) { for(int i=0;i!=content.size();++i) at+=(content[i]=='\n'); }
	void movewithImage(string content) { at+=content.size()/WIDTH+(content.size()%WIDTH!=0); }

	void begin() { putcs('\n'); at=1; }
	void end() { moveto(HEIGHT); }
	void put(int i,string content) { moveto(i); cout<<content; movewith(content); }
	void putImage(int i,string content) { moveto(i); cout<<content; movewithImage(content); }

	void indent(string& content, int j) // 缩进j个空格
	{
		for(int i=0;i!=j;++i) content = " " + content;
	}
	void putTH(string part, string content="") // 打印设计
	{
		static int lines;
		if(part=="begin") { begin(); lines=0; }
		if(part=="head") { indent(content,4); put(top, content); }
		if(part=="image") putImage(top+DIS, content);
		if(part=="notice") put(top+DIS, content);
		if(part=="body") { indent(content,16); put(at+((lines++)?1:dis), content); }
		if(part=="bottom") put(bot, content);
		if(part=="end") end();
	}

	static const int maxBody = 10;
	int lineNum;
	bool useImage;
	string head;
	string image;
	string notice;
	string body[maxBody];
	string bottom;

public:
	PUTScreen(): lineNum(0), useImage(false) {}
	PUTScreen& clear() { lineNum = 0; useImage = false; head = notice = bottom = ""; return *this; }
	PUTScreen& clearBody() { lineNum = 0; return *this; }

	PUTScreen& setHead(string _head) { head = _head; return *this; }
	PUTScreen& setNotice(string _notice) { notice = _notice; return *this; }
	PUTScreen& setImage(string _image) { useImage=true; image = _image; return *this; }
	PUTScreen& addBody(string _body) { body[lineNum++] = _body; return *this; }
	PUTScreen& setBottom(string _bottom) { bottom = _bottom; return *this; }
	PUTScreen& setBody(string _body) { return clearBody(). addBody(_body); }

	PUTScreen& print() // 打印逻辑
	{
		putTH("begin");
		putTH("head", head);
		if(useImage) putTH("image", image); else putTH("notice", notice);
		for(int i=0;i<lineNum;++i) putTH("body", body[i]);
		putTH("bottom", bottom);
		putTH("end");
		return *this;
	}
}PUT;

#endif