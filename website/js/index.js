$(function()
{
	$('.top').css('width',100/$('.top').length+'%');
	b_count=0; g_count=0;
	$('.boy').each(function()
	{
		$(this).css('top',40+b_count*50);
		++b_count;
	});
	$('.girl').each(function()
	{
		$(this).css('top',40+g_count*50);
		++g_count;
	});
	show_content();
});
//--------------------------------------课程信息--------------------------------------------
function Course(var_name,name,email,tel,office,work_time,a1_name,a1_email,a1_tel,a2_name,a2_email,a2_tel)
{
	this.var_name=var_name;
	this.name=name;
	this.email=email;
	this.tel=tel;
	this.office=office;
	this.work_time=work_time;

	this.a1_name=a1_name;	//assistant 1
	this.a1_email=a1_email;
	this.a1_tel=a1_tel;

	this.a2_name=a2_name;	//assistant 2
	this.a2_email=a2_email;
	this.a2_tel=a2_tel;
}

function Content(x1,x2,x3,x4,x5,x6,x7,x8)
{
	this.x1=x1;
	this.x2=x2;
	this.x3=x3;
	this.x4=x4;
	this.x5=x5;
	this.x6=x6;
	this.x7=x7;
	this.x8=x8;
}

function score(a,av,b,bv,c,cv,d,dv,e,ev)
{
	this.a=a;
	this.av=av;
	this.b=b;
	this.bv=bv;
	this.c=c;
	this.cv=cv;
	this.d=d;
	this.dv=dv;
	this.e=e;
	this.ev=ev;
}

function book(book1,book2,book3,book4)
{
	this.book1=book1;
	this.book2=book2;
	this.book3=book3;
	this.book4=book4;
}

function other(other)
{
	this.other=other;
}

//------------------------------读取信息 Course in--------------------------------------------------
var fbs=new Course('fbs', '姚斌', 'yaobin@cs.sjtu.edu.cn', '15921379438', '', '', '李格非', 'oizz01@sjtu.edu.cn', '', '', '', '');
fbs.score=new score('paper', '10%，英文summary，中or英presentation', '大作业', '60%，两人一组（赵超），presentation+系统演示', '作业', '30%', '', '', '', '');
fbs.book=new book('Cloud computing bible(英文): Barrie Sosinsky', '《云计算(第2版)》刘鹏 编,电子工业出版社', '《实战Hadoop》刘鹏 编,电子工业出版社', '');
fbs.linking='http://www.cs.sjtu.edu.cn/~yaobin/';
fbs.homework='第三周or助教确定论文题目后，开始做paper；六个编程大作业和赵超一起做；作业随留随做；课前课后看看分布式的书。【作业抄送给老师！】';
fbs.other='编程方面，学习Hadoop的使用；知识方面，学习云计算和大数据相关内容。';
var cxsjyy=new Course('cxsjyy', '朱其立', 'kzhu@cs.sjtu.edu.cn', '34204592', '电群 3-541', '随时', '罗徐生（工作时间：周二16:00-17:00）', 'freefish_6174@126.com', '', '', '', '');
cxsjyy.score=new score('quiz', '10%', '特别参与', '5%', '作业', '30-40%', 'project', '25%', '课上考试', '20-30%');
cxsjyy.book=new book('Programming Languages Principles and Paradigms by Allen Tucker and Robert Noonan, McGraw Hill / 2009-5-1 (Also published by Tsinghua University Press and available at the University Textbook Office).', 'Practical Foundations for Programming Languages by Robert Harper, Cambridge University Press.', 'Types and Programming Languages by Benjamin C. Pierce, The MIT Press.', 'Programming Languages: Application and Interpretation by Shriram Krishnamurthi, Brown, Online.');
cxsjyy.linking='http://www.cs.sjtu.edu.cn/~kzhu/cs383/';
cxsjyy.homework='注意随时准备课上quiz；project和作业随留随做；特别参与的5%是什么啊？';
cxsjyy.other='编程方面，要接触各种语言；上课，专心听讲；课下，好好看ppt和书。';
var byyy=new Course('byyy', '张冬茉', 'zhang-dm@cs.sjtu.edu.cn', '', '', '', '', '', '', '', '', '');
byyy.score=new score('期末', '70%', '出勤', '30%，18分直接给，12分三次随机点名（作业不算分）', '', '', '', '', '', '');
byyy.book=new book('', '', '', '');
byyy.linking='';
byyy.homework='记下来她都讲了哪些知识点，自己看书补足。';
byyy.other='老师讲得很慢，上课注意她讲了什么，主要是看书学习。';
var jsjxtjg=new Course('jsjxtjg', '朱燕民', 'yzhu@cs.sjtu.edu.cn', '13524421842', '电群 3-420(505?)', '', '李娟', 'sjtucs_comparc@163.com', '18217680871', '', '', '');
jsjxtjg.score=new score('', '', '', '', '', '', '', '', '', '');
jsjxtjg.book=new book('【教材】Computer architecture a quantitative approach, 5th ed., by John L. Hennessy and David A. Patterson.', 'Computer Organization and Architecture: Designing for Performance, 7th ed. William Stallings.', 'Computer Organization and Design: The Hardware Software Interface, David A. Patterson, John L. Hennessy, 3ed.', 'Computer.Architecture.-.A.Quantitative.Approach.4th.ed.-. J.Hennessy, D.Patterson.');
jsjxtjg.linking='http://cs.sjtu.edu.cn/~yzhu/';
jsjxtjg.homework='暂时只有听讲。';
jsjxtjg.other='较重的口音，仅上了一节课，下节课再认真听听看。';
var sfyfzx=new Course('sfyfzx', '任庆生', 'ren-qs@cs.sjtu.edu.cn', '34204420', '电群 3-523', '', '', '', '', '', '', '');
sfyfzx.score=new score('期末', '70%', '作业', '30%', '', '', '', '', '', '');
sfyfzx.book=new book('【教材】算法引论——一种创造性方法，Udi Manberi著，黄林鹏等译，电子工业出版社', '', '', '');
sfyfzx.linking='';
sfyfzx.homework='把他课上问题都证了，算导多看看。作业下周二暂时不用交，是教材上的2.14, 2.15, 2.29, 2.39。其中，15题，81改成51。【已完成，周二交】';
sfyfzx.other='暂时还没助教；老师讲得很慢，课上把他提的问题都证了，下课自己看算法导论去。';
var rjgc=new Course('rjgc', '盛斌', 'shengbin@cs.sjtu.edu.cn', '15026790946', '电群 3-511', '', '王睿', 'jhcz@sjtu.edu.cn', '', '程泽洲', 'chengzezhou@qq.com', '');
rjgc.score=new score('project', '70%（软件工程实践课的100%），三人小组一起做', 'quiz和作业', '30%', '', '', '', '', '', '');
rjgc.book=new book('', '', '', '');
rjgc.linking='';
rjgc.homework='加入讨论组；准备好周五的quiz；周五问好实践课的时间。';
rjgc.other='老师口语极差，课很不好听，自己多看ppt和书；课上如何待定，暂定不当组长，课上自己学习；做好project，准备好quiz。';
var gkc=new Course('gkc', '张士文', 'shiwen@Yeah.net', '34204436', '电群 4-314', '', '', '', '', '', '', '');
gkc.score=new score('', '', '', '', '', '', '', '', '', '');
gkc.book=new book('', '', '', '');
gkc.linking='http://eelab.sjtu.edu.cn/KC';
gkc.homework='';
gkc.other='';
var dxyw=new Course('dxyw', '', '', '', '', '', '', '', '', '', '', '');
dxyw.score=new score('课堂表现', '5%', '平时作业', '25%（约4次，有一次是10分，随堂作业，小组讨论写成文字稿交给助教）', '个人大作业', '30%', '小组作业', '40%（主题：文学的美：有文学相伴的人生更美！）', '', '');
dxyw.book=new book('', '', '', '');
dxyw.linking='';
dxyw.homework='';
dxyw.other='';
//------------------------------读取信息 Course out--------------------------------------------------

//------------------------------读取信息 备忘 in--------------------------------------------------
var content=new Content('火车优惠卡刷不了', '克斯勒', '', '', '', '', '', '');
//------------------------------读取信息 备忘 out--------------------------------------------------

//-------------------------------------显示课程信息--------------------------------
function show(c)
{
	$('#arrange').html('');
	$('#teacher').html('<table>\
		<tr><th>教师</th><td>'+c.name+'</td></tr>\
		<tr><th>邮箱</th><td>'+c.email+'</td></tr>\
		<tr><th>电话</th><td>'+c.tel+'</td></tr>\
		<tr><th>办公室</th><td>'+c.office+'</td></tr>\
		<tr><th>办公时间</th><td>'+c.work_time+'</td></tr>\
		</table>');
	if(c.a1_name)
		$('#teacher').append('<table>\
			<tr><th>助教</th><td>'+c.a1_name+'</td></tr>\
			<tr><th>邮箱</th><td>'+c.a1_email+'</td></tr>\
			<tr><th>电话</th><td>'+c.a1_tel+'</td></tr>\
			</table>');
	if(c.a2_name)
		$('#teacher').append('<table>\
			<tr><th>助教</th><td>'+c.a2_name+'</td></tr>\
			<tr><th>邮箱</th><td>'+c.a2_email+'</td></tr>\
			<tr><th>电话</th><td>'+c.a2_tel+'</td></tr>\
			</table>');
	$('#linking').attr('href',c.linking);
	$('#score').attr('onclick','show_score('+c.var_name+')');
	$('#book').attr('onclick','show_book('+c.var_name+')');
	$('#homework').attr('onclick','show_homework('+c.var_name+')');
	$('#other').attr('onclick','show_other('+c.var_name+')');
	$('#schedule_boy').css('opacity',0);
	$('#schedule_girl').css('opacity',0);
}
function show_book(c)
{
	show(c);
	$('#arrange').html('<table>\
		<tr><td>'+c.book.book1+'</td></tr>\
		</table>')
	if(c.book.book2)
		$('#arrange').append('<table>\
		<tr><td>'+c.book.book2+'</td></tr>\
		</table>')
	if(c.book.book3)
		$('#arrange').append('<table>\
		<tr><td>'+c.book.book3+'</td></tr>\
		</table>')
	if(c.book.book4)
		$('#arrange').append('<table>\
		<tr><td>'+c.book.book4+'</td></tr>\
		</table>')
}
function show_score(c)
{
	$('#arrange').html('');
	if(c.score.a) $('#arrange').append('<table><tr><th>'+c.score.a+'</th><td>'+c.score.av+'</td></tr></table>');
	if(c.score.b) $('#arrange').append('<table><tr><th>'+c.score.b+'</th><td>'+c.score.bv+'</td></tr></table>');
	if(c.score.c) $('#arrange').append('<table><tr><th>'+c.score.c+'</th><td>'+c.score.cv+'</td></tr></table>');
	if(c.score.d) $('#arrange').append('<table><tr><th>'+c.score.d+'</th><td>'+c.score.dv+'</td></tr></table>');
	if(c.score.e) $('#arrange').append('<table><tr><th>'+c.score.e+'</th><td>'+c.score.ev+'</td></tr></table>');
}

function show_homework(c)
{
	$('#arrange').html('');
	$('#teacher').html(c.homework);
	$('#schedule_boy').css('opacity',0);
	$('#schedule_girl').css('opacity',0);
}

function show_other(c)
{
	show(c);
	$('#arrange').html(c.other);
}

var who=0;
function show_schedule()
{
	show('');
	$('#teacher').html('');
	$('#arrange').html('');
	if(who!=0)
	{
		$('#schedule_girl').css('opacity',0);
		$('#schedule_boy').css('opacity',0.4);
		who=0;
	}
	else
	{
		$('#schedule_girl').css('opacity',0.4);
		$('#schedule_boy').css('opacity',0);
		who=1;
	}
	$('#course button').each(function()
	{
		$(this).css('background-image','url(img/button.png)');
	})
}

function show_content()
{
	$('#content').html('<li>'+content.x1+'</li><li>'+content.x2+'</li><li>'+content.x3+'</li><li>'+content.x4+'</li>\
		<li>'+content.x5+'</li><li>'+content.x6+'</li><li>'+content.x7+'</li><li>'+content.x8+'</li>');
}

//将选中课程按钮颜色改为红色
$('#course button').mouseup(function()
{
	$('#course button').each(function()
	{
		$(this).css('background-image','url(img/button.png)');
	})
	$(this).css('background-image','url(img/button_red.png)');
})
