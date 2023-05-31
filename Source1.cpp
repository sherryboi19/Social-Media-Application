#pragma warning(disable : 4996)
#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<ctime>
using namespace std;

class Node 
{
public:
	char ch;
	bool terminal;
	Node* child[26];

	Node(char c)
	{
		ch = c;
		terminal = false;
		for (int i = 0; i < 26; i++)
		{
			child[i] = NULL;
		}
	}
};

class Tries
{
public:
	Node* root;
	int count;
	Tries()
	{
		root = createNode('\0');
	}

	Node* createNode(char c)
	{
		Node* newNode = new Node(c);
		return newNode;
	}

	void Insert(string word)
	{
		Node* temp = root;
		char ch = '\0';
		int pos = 0;
		for (int i = 0; i < word.length(); i++)
		{

			ch = word[i];
			pos = ch - 'a';
			if (temp->child[pos] == NULL)
			{
				temp->child[pos] = createNode(ch);
				count++;
			}
			temp = temp->child[pos];
		}
		temp->terminal = true;
	}

	void Display(Node* temp, string word)
	{
		if (temp == NULL)
			return;

		if (temp != root)
			word = word + temp->ch;
		if (temp->terminal)
			cout << count << " " << word << endl;
		for (int i = 0; i < 26; i++)
		{
			Display(temp->child[i], word);
		}
	}

	Node* search(Node* temp, string key, int index)
	{

		if (temp == NULL)
		{
			return NULL;
		}

		char ch = key[index];

		if (temp->terminal && index == key.size())
		{
			return temp;
		}
		if (ch == '\0')
		{
			return NULL;
		}
		int i = ch - 'a';

		return	search(temp->child[i], key, ++index);
	}
};

class Time
{
	int hr, min, sec;
public:
	Time(int h = 0, int m = 0, int s = 0) :hr(h), min(m), sec(s)
	{
	}
	void setHr(int h)
	{
		hr = h;
	}
	void setMin(int m)
	{
		min = m;
	}
	void setSec(int s)
	{
		sec = s;
	}
	int getHr()
	{
		return hr;
	}
	int getMin()
	{
		return min;
	}
	int getSec()
	{
		return sec;
	}
	void addTime(int m)
	{
		min = m % 60;
		hr += m / 60;
	}
	void setTime(int h, int m, int s)
	{
		hr = h;
		min = m;
		sec = s;
	}
	void DisplayTime()
	{
		cout << setw(2) << setfill('0') << hr << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << sec;
	}
};

class Date
{
	int day;
	int month;
	int year;
public:
	Date(int d = 0, int m = 0, int y = 0)
	{
		day = d;
		month = m;
		year = y;
	}
	void setDay(int d)
	{
		day = d;
	}
	void setMonth(int m)
	{
		month = m;
	}
	void setYear(int y)
	{
		year = y;
	}
	int getDay()
	{
		return day;
	}
	int getMonth()
	{
		return month;
	}
	int getYear()
	{
		return year;
	}
	void displaydate()
	{
		cout << day << "-" << month << "-" << year << endl;
	}
};

int cmpDate(Date d1, Date d2)
{
	if (d1.getYear() < d2.getYear())
	{
		return 2;
	}
	else if (d2.getYear() < d1.getYear())
	{
		return 1;
	}
	else if (d2.getYear() == d2.getYear())
	{
		if (d1.getMonth() < d2.getMonth())
		{
			return 2;
		}
		else if (d2.getMonth() < d1.getMonth())
		{
			return 1;
		}
		else if (d2.getMonth() == d1.getMonth())
		{
			if (d1.getDay() < d2.getDay())
			{
				return 2;
			}
			else if (d2.getDay() < d1.getDay())
			{
				return 1;
			}
			else if (d2.getDay() == d1.getDay())
			{
				return 0;
			}
		}
	}
}

int cmpTime(Time t1, Time t2)
{
	if (t1.getHr() > t2.getHr())
	{
		return 1;
	}
	if (t1.getHr() < t2.getHr())
	{
		return 2;
	}
	if (t1.getHr() == t2.getHr())
	{
		if (t1.getMin() > t2.getMin())
		{
			return 1;
		}
		if (t1.getMin() < t2.getMin())
		{
			return 2;
		}
		if (t1.getMin() == t2.getMin())
		{
			if (t1.getSec() > t2.getSec())
			{
				return 1;
			}
			if (t1.getSec() < t2.getSec())
			{
				return 2;
			}
			if (t1.getSec() == t2.getSec())
			{
				return 0;
			}
		}
	}
}

class Message
{
	string RName;
	string Text;
	Time msgTime;
	Date msgDate;
	Message* next;
	Message* prev;
public:
	Message(string tn = "NONE", string ttext = " ") :RName(tn), Text(ttext)
	{
		next = NULL;
		prev = NULL;
	}
	void setMsg(string n, string t, Time mt, Date md)
	{
		RName = n;
		Text = t;
		msgTime = mt;
		msgDate = md;
	}
	void setNext(Message* tn)
	{
		next = tn;
	}
	void setPrev(Message* tp)
	{
		prev = tp;
	}
	void setRecieverName(string tn)
	{
		RName = tn;
	}
	void setMText(string t)
	{
		Text = t;
	}
	void setMTime(Time t)
	{
		msgTime = t;
	}
	void setMDate(Date d)
	{
		msgDate = d;
	}
	Message* getNext()
	{
		return next;
	}
	Message* getPrev()
	{
		return prev;
	}
	string getRecieverName()
	{
		return RName;
	}
	string getMText()
	{
		return Text;
	}
	Time getMTime()
	{
		return msgTime;
	}
	Date getMDate()
	{
		return msgDate;
	}
	void DisplayMsg()
	{
		cout << endl << Text << endl << endl;
		cout << "Recived By : " << RName << endl << endl;
		cout << "Date : ";
		msgDate.displaydate();
		cout << "Time : ";
		msgTime.DisplayTime();
		cout << endl << endl;
	}
};

class MsgQueue
{
	Message* Head;
	Message* Tail;
public:
	MsgQueue()
	{
		Head = NULL;
		Tail = NULL;
	}
	void setHead(Message* temp)
	{
		Head = temp;
	}
	void setTail(Message* temp)
	{
		Tail = temp;
	}
	Message* getHead()
	{
		return Head;
	}
	Message* getTail()
	{
		return Tail;
	}
	void Enqueue(Message temp)
	{
		Message* mynode = new Message;
		mynode->setMsg(temp.getRecieverName(), temp.getMText(), temp.getMTime(), temp.getMDate());
		if ((Head == NULL) && (Tail == NULL))
		{
			mynode->setNext(mynode);
			mynode->setPrev(mynode);
			Head = mynode;
			Tail = mynode;
			return;
		}
		mynode->setNext(Head);
		mynode->setPrev(Tail);
		Tail->setNext(mynode);
		Head->setPrev(mynode);
		Tail = mynode;
	}

	Message Dequeue()
	{
		Message temp1 = *Head;
		Message* temp = Head;
		temp->getNext()->setPrev(temp->getPrev());
		temp->getPrev()->setNext(temp->getNext());
		Head = temp->getNext();
		temp->setNext(NULL);
		temp->setPrev(NULL);
		delete temp;
		return temp1;
	}
	Message Rear()
	{
		return *Head;
	}
	bool isEmpty()
	{
		if (Head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void DisplayMsgs()
	{
		Message* temp = Head;
		if (Head == NULL)
		{
			cout << " NO CONVERSATION HISTORY " << endl;
			return;
		}
		cout << " CONVERSATION " << endl << endl;
		do
		{
			temp->DisplayMsg();
			cout << endl;
			temp = temp->getNext();
		} while (temp != Head);
	}
};

class Comment
{
	string CName;
	string Text;
	Time CTime;
	Date CDate;
	Comment* next;
	Comment* prev;
public:
	Comment(string tn = "NONE", string ttext = " ") :CName(tn), Text(ttext)
	{

	}
	void setCmnt(Comment c)
	{
		CName = c.getCName();
		Text = c.getCText();
		CTime = c.getCTime();
		CDate = c.getCDate();
	}
	void setNext(Comment* tn)
	{
		next = tn;
	}
	void setPrev(Comment* tp)
	{
		prev = tp;
	}
	void setCName(string tn)
	{
		CName = tn;
	}
	void setCText(string t)
	{
		Text = t;
	}
	void setCTime(Time t)
	{
		CTime = t;
	}
	void seCtDate(Date d)
	{
		CDate = d;
	}
	Comment* getNext()
	{
		return next;
	}
	Comment* getPrev()
	{
		return prev;
	}
	string getCName()
	{
		return CName;
	}
	string getCText()
	{
		return Text;
	}
	Time getCTime()
	{
		return CTime;
	}
	Date getCDate()
	{
		return CDate;
	}
	void DisplayComment()
	{
		cout << "\n";
		cout << "\t\t\t\t\t\tCOMMENTER NAME :" << getCName() << "\n";
		cout << "\t\t\t\t\t\tCOMMENT TEXT :" << getCText() << "\n";
		cout << "\t\t\t\t\t\tCOMMENT DATE : ";
		getCDate().displaydate();
		cout << "\t\t\t\t\t\tCOMMENT TIME : ";
		getCTime().DisplayTime();
		cout << "\n";
	}
};

class CmntStack
{
	int num;
	Comment* Head;
	Comment* Tail;
public:
	CmntStack()
	{
		num = 0;
		Head = NULL;
		Tail = NULL;
	}
	int getNumCmnts()
	{
		return num;
	}
	Comment* getHead()
	{
		return Head;
	}
	Comment* getTail()
	{
		return Tail;
	}
	void setHead(Comment* h)
	{
		Head = h;
	}
	void setTail(Comment* t)
	{
		Tail = t;
	}
	void AddCmnt(Comment c)
	{
		Comment* mynode = new Comment;
		mynode->setCmnt(c);
		if ((Head == NULL) && (Tail == NULL))
		{
			mynode->setNext(mynode);
			mynode->setPrev(mynode);
			Head = mynode;
			Tail = mynode;
			num++;
			return;
		}
		mynode->setNext(Head);
		Head->setPrev(mynode);
		mynode->setPrev(Tail);
		Head = mynode;
		Tail->setNext(Head);
		num++;
	}
	void UpdateCmnt(string n, int i)
	{
		if (i > num)
		{
			cout << "NO SUCH COMMENT EXIST..." << endl;
			return;
		}
		string ts;
		Comment* temp = Head;
		int count = 1;
		do
		{
			if ((count == i) && (temp->getCName() == n))
			{
				temp->DisplayComment();
				cin.ignore();
				cout << "ENTER NEW COMMENT : ";
				getline(cin, ts);
				temp->setCText(ts);
				cout << "COMMENT UPDATED...." << endl;
				return;
			}
			temp = temp->getNext();
			count++;
		} while (temp != Head);
	}
	void DeleteCmnt(string n, int i)
	{
		if (i > num)
		{
			cout << "No Such Comment Exsist..." << endl;
			return;
		}
		Comment* temp = Head;
		int count = 1;
		do
		{
			if ((count == i) && (temp->getCName() == n))
			{
				temp->DisplayComment();
				cout << "Deleting Comment.." << endl;
				temp->getNext()->setPrev(temp->getPrev());
				temp->getPrev()->setNext(temp->getNext());
				if (temp == Head)
				{
					Head = temp->getNext();
				}
				if (temp == Tail)
				{
					Tail = temp->getPrev();
				}
				temp->setNext(NULL);
				temp->setPrev(NULL);
				delete temp;
				cout << "Comment Deleted Successfully.." << endl;
				num--;
				return;
			}
			temp = temp->getNext();
			count++;
		} while (temp != Head);
	}
	void view_LatestComment()
	{
		Comment* temp = Head;
		if (Head == NULL)
		{
			cout << "NO COMMENTS " << endl;
			return;
		}
		else
		{
			temp->DisplayComment();
		}
	}
	void ViewComments()
	{
		int count = 1;
		Comment* temp = Head;
		if (Head == NULL)
		{
			cout << "NO COMMENTS " << endl;
			return;
		}
		else
		{
			do
			{
				cout << count << endl;
				temp->DisplayComment();
				count++;
				temp = temp->getNext();
			} while (temp != Head);
		}
	}
};

class Post
{
	string owner;
	Date PDate;
	Time PTime;
	string PText;
	CmntStack PComment;
	Post* next;
	Post* prev;
public:
	Post(string o = " ", string t = " ") :PText(t), owner(o)
	{
		next = NULL;
		prev = NULL;
	}
	void setNext(Post* tn)
	{
		next = tn;
	}
	void setPrev(Post* tp)
	{
		prev = tp;
	}
	Post* getNext()
	{
		return next;
	}
	Post* getPrev()
	{
		return prev;
	}
	void setPost(string o, string t, Time tm, Date d)
	{
		owner = o;
		PDate = d;
		PTime = tm;
		PText = t;
	}
	void setOwner(string o)
	{
		owner = o;
	}
	void setPText(string t)
	{
		PText = t;
	}
	void setPTime(Time t)
	{
		PTime = t;
	}
	void setPDate(Date d)
	{
		PDate = d;
	}
	string getOwner()
	{
		return owner;
	}
	Date getPostDate()
	{
		return PDate;
	}
	Time getPostTime()
	{
		return PTime;
	}
	string getPostText()
	{
		return PText;
	}
	void DisplayPost()
	{
		cout << "\t\t\t\t\t\tTEXT: " << getPostText() << "\n";
		cout << "\t\t\t\t\t\tDATE: ";
		getPostDate().displaydate();
		cout << "\n";
		cout << "\t\t\t\t\t\tTIME: ";
		getPostTime().DisplayTime();
		cout << "\n";
		cout << "\t\t\t\t\tCOMMENT ON POST: ";
		PComment.view_LatestComment();

	}
	void DisplayComments()
	{
		PComment.ViewComments();
	}
	void AddComm(Comment C)
	{
		PComment.AddCmnt(C);
	}
	void UpdateComm(string tn, int i)
	{
		PComment.UpdateCmnt(tn, i);
	}
	void DelComm(string tn, int i)
	{
		PComment.DeleteCmnt(tn, i);
	}
};

class PostStack
{
	int num;
	Post* Head;
	Post* Tail;
public:
	PostStack()
	{
		num = 0;
		Head = NULL;
		Tail = NULL;
	}
	int getNumPosts()
	{
		return num;
	}
	Post* getHead()
	{
		return Head;
	}
	Post* getTail()
	{
		return Tail;
	}
	void setHead(Post* h)
	{
		Head = h;
	}
	void setTail(Post* t)
	{
		Tail = t;
	}
	void AddPostt(Post c)
	{
		Post* mynode = new Post;
		mynode->setPost(c.getOwner(), c.getPostText(), c.getPostTime(), c.getPostDate());
		if ((Head == NULL) && (Tail == NULL))
		{
			mynode->setNext(mynode);
			mynode->setPrev(mynode);
			Head = mynode;
			Tail = mynode;
			num++;
			return;
		}
		mynode->setNext(Head);
		Head->setPrev(mynode);
		mynode->setPrev(Tail);
		Head = mynode;
		Tail->setNext(Head);
		num++;
	}
	void UpdatePost(int i)
	{
		if (i > num)
		{
			cout << "No Such Post Exsist..." << endl;
			return;
		}
		string ts;
		Post* temp = Head;
		int count = 1;
		do
		{
			if (count == i)
			{
				temp->DisplayPost();
				cout << "Enter Updated Post Text : ";
				getline(cin, ts);
				temp->setPText(ts);
				cout << "Post Updated.." << endl;
				return;
			}
			temp = temp->getNext();
			count++;
		} while (temp != Head);
	}
	void DeletePost(string n, int i)
	{
		if (i > num)
		{
			cout << "No Such Post Exsist..." << endl;
			return;
		}
		Post* temp = Head;
		int count = 1;
		do
		{
			if ((count == i) && (temp->getOwner() == n))
			{
				temp->DisplayPost();
				cout << "Deleting Post.." << endl;
				temp->getNext()->setPrev(temp->getPrev());
				temp->getPrev()->setNext(temp->getNext());
				if (temp == Head)
				{
					Head = temp->getNext();
				}
				if (temp == Tail)
				{
					Tail = temp->getPrev();
				}
				temp->setNext(NULL);
				temp->setPrev(NULL);
				delete temp;
				cout << "Post Deleted Successfully.." << endl;
				num--;
				return;
			}
			temp = temp->getNext();
			count++;
		} while (temp != Head);
	}
	void ViewPosts()
	{
		int count = 1;
		Post* temp = Head;
		if (Head == NULL)
		{
			cout << "\t\t\t\t\t\tNO POST ADDED YET...!" << endl;
			return;
		}
		else
		{
			do
			{
				cout << count << endl;
				temp->DisplayPost();
				count++;
				temp = temp->getNext();
			} while (temp != Head);
		}
	}
	void ViewCommentOnPost(int i, string n)
	{
		if (i > num)
		{
			cout << "NO SUCH POST EXIST...!" << endl;
			return;
		}
		Post* temp = Head;
		int count = 1;
		do
		{
			if ((count == i) && (temp->getOwner() == n))
			{
				temp->DisplayComments();
			}
			temp = temp->getNext();
			count++;
		} while (temp != Head);
	}
	int GetPostNo()
	{
		return num;
	}
	void View_All_Comments(int i)
	{
		if (i > num)
		{
			cout << "NO SUCH POST EXIST...!" << endl;
			return;
		}
		Post* temp = Head;
		int count = 1;
		do
		{
			if ((count == i))
			{
				temp->DisplayComments();
			}
			temp = temp->getNext();
			count++;
		} while (temp != Head);
	}
	void addComment(int i, Comment c)
	{
		if (i > num)
		{
			cout << "NO SUCH POST EXIST...!" << endl;
			return;
		}
		Post* temp = Head;
		int count = 1;
		do
		{
			if ((count == i))
			{
				temp->AddComm(c);
				break;
			}
			temp = temp->getNext();
			count++;
		} while (temp != Head);
	}
	void UpdateComment(int i, string tn)
	{
		if (i > num)
		{
			cout << "NO SUCH POST EXIST...!" << endl;
			return;
		}
		Post* temp = Head;
		int count = 1;
		do
		{
			if ((count == i))
			{
				temp->UpdateComm(tn, i);
				break;
			}
			temp = temp->getNext();
			count++;
		} while (temp != Head);
	}
	void DelComment(string tn, int i)
	{
		if (i > num)
		{
			cout << "NO SUCH POST EXIST...!" << endl;
			return;
		}
		Post* temp = Head;
		int count = 1;
		do
		{
			if ((count == i))
			{
				temp->DelComm(tn, i);
				break;
			}
			temp = temp->getNext();
			count++;
		} while (temp != Head);
	}
};

class Conversation
{
private:
	MsgQueue frndMSG;;
public:
	Conversation()
	{

	}
	void addMsg(Message T)
	{
		frndMSG.Enqueue(T);
	}
	bool SearchMsg()
	{
		Message* temp = frndMSG.getHead();
		string tn;
		cout << "ENTER MESSAGE : ";
		getline(cin, tn);
		if (frndMSG.getHead() == NULL)
		{
			cout << "Messages are Empty...." << endl << endl;
			return false;
		}
		Message t1 = *(frndMSG.getHead());
		string tm = t1.getMText();
		if (tm == tn)
		{
			return true;
		}
		t1 = *(frndMSG.getTail());
		tm = t1.getMText();
		if (tm == tn)
		{
			return true;
		}
		do
		{
			t1 = *temp;
			tm = t1.getMText();
			if (tm == tn)
			{
				return true;
			}
			temp = temp->getNext();
		} while (temp != frndMSG.getHead());
		return false;
	}
	void DisplayConvo()
	{
		frndMSG.DisplayMsgs();
	}
};

class Frnd {
private:
	string Fname;
	Conversation convo;
	Frnd* next;
	Frnd* prev;
public:
	Frnd(string tn = "None") :Fname(tn)
	{

	}
	void setNext(Frnd* temp)
	{
		next = temp;
	}
	void setPrev(Frnd* temp)
	{
		prev = temp;
	}
	void setName(string tn)
	{
		Fname = tn;
	}
	string getFriendName()
	{
		return Fname;
	}
	Frnd* getNext()
	{
		return next;
	}
	Frnd* getPrev()
	{
		return prev;
	}
	void Add_Message(Message m)    
	{
		convo.addMsg(m);
	}
	void View_Chat()
	{
		convo.DisplayConvo();
	}
};

class FriendList
{
private:
	Frnd* Head;
	Frnd* Tail;
public:
	FriendList()
	{
		Head = NULL;
		Tail = NULL;
	}
	Frnd* GetHead()
	{
		return Head;
	}
	void AddFriend(string fn)
	{
		Frnd* mynode = new Frnd(fn);
		if ((Head == NULL) && (Tail == NULL))
		{
			mynode->setNext(mynode);
			mynode->setPrev(mynode);
			Head = mynode;
			Tail = mynode;
			return;
		}
		mynode->setNext(Head);
		Head->setPrev(mynode);
		mynode->setPrev(Tail);
		Head = mynode;
		Tail->setNext(Head);
	}
	void displayfriendLIst()
	{
		Frnd* temp = Head;
		int i = 1;
		do
		{
			cout << i << " . " << temp->getFriendName() << endl;
			i++;
		} while (temp != Head);
	}
	void UnFriend(string str)
	{

		Frnd* temp = Head;
		if (Head == NULL)
		{
			cout << "List Is Empty...." << endl << endl;
			return;
		}
		if (Head->getFriendName() == str)
		{
			temp->getNext()->setPrev(temp->getPrev());
			temp->getPrev()->setNext(temp->getNext());
			Head = temp->getNext();
			temp->setNext(NULL);
			temp->setPrev(NULL);
			delete temp;
			return;
		}
		Frnd* ptr = Tail;
		if (Tail->getFriendName() == str)
		{
			ptr->getNext()->setPrev(ptr->getPrev());
			ptr->getPrev()->setNext(ptr->getNext());
			Tail = ptr->getPrev();
			ptr->setNext(NULL);
			ptr->setPrev(NULL);
			delete ptr;
			return;
		}
		do
		{
			if (temp->getFriendName() == str)
			{
				temp->getNext()->setPrev(temp->getPrev());
				temp->getPrev()->setNext(temp->getNext());
				temp->setNext(NULL);
				temp->setPrev(NULL);
				delete temp;
				return;
			}
			temp = temp->getNext();
		} while (temp != Head);
	}
	Frnd* getFriend(string n)     
	{
		Frnd* temp = Head;
		if (temp == NULL)
		{
			return NULL;
		}
		do
		{
			if (temp->getFriendName() == n)
			{
				return temp;
			}
		} while (temp != Head);
		return NULL;
	}

	/*FriendList * GetOneFriend(Frnd *temp)
	{

		if (temp==NULL)
		{
			return NULL;
		}
		else
		{
			return temp->getFriendName();
		}

	}*/
};

class User
{
	string Name;
	string PhNum;
	string Username;
	string Password;
	FriendList FL;
	PostStack Posts;
	FriendList friend_request;
public:
	User(string tn = "NONE", string tp = "00", string tun = "NONE", string tpas = "NONE") :Name(tn), PhNum(tp), Username(tun), Password(tpas)
	{
		Posts.setHead(NULL);
		Posts.setTail(NULL);
	}
	void setName(string tn)
	{
		Name = tn;
	}
	void setPhNum(string tp)
	{
		PhNum = tp;
	}
	void setUserName(string tun)
	{
		Username = tun;
	}
	void setPassword(string tpas)
	{
		Password = tpas;
	}
	string getName()
	{
		return Name;
	}
	string getPhNum()
	{
		return PhNum;
	}
	string getUserName()
	{
		return Username;
	}
	string getPassword()
	{
		return Password;
	}
	FriendList getFriendList()
	{
		return FL;
	}
	PostStack getPosts()
	{
		return Posts;
	}
	void AddFrirnd(string f)
	{
		FL.AddFriend(f);
	}
	void UnFriend(string fn)
	{
		FL.UnFriend(fn);
	}
	void diplayComments(int i)
	{
		Posts.View_All_Comments(i);
	}
	void DisplayUser()
	{
		cout << "\t\t\t\t\t\t\t\tUSER PORTAL\n";
		cout << "\t\t\t\t\t\t\tNAME : " << getName() << '\n';
		cout << "\t\t\t\t\t\t\tMOBILE NUMBER : " << getPhNum() << '\n';
		cout << "\t\t\t\t\t\t\tUSER NAME : " << getUserName() << "\n";
		cout << "\t\t\t\t\t\t\tALL POSTS : " << "\n";
		Posts.ViewPosts();
	}
	void DisplayPosts()
	{
		Posts.ViewPosts();
	}
	int getPostN()
	{
		return Posts.getNumPosts();
	}
	void addPost(Post c)
	{
		Posts.AddPostt(c);
	}
	void DeletePost(string n, int i)
	{
		Posts.DeletePost(n, i);
	}
	void UpdatePost(int i)
	{
		Posts.UpdatePost(i);
	}
	void AddC(int i, Comment C)
	{
		Posts.addComment(i, C);
	}
	void UpdateC(string tn, int i)
	{
		Posts.UpdateComment(i, tn);
	}
	void DelC(string tn, int i)
	{
		Posts.DelComment(tn, i);
	}
	void addFriend_request(string tn)
	{
		friend_request.AddFriend(tn);
	}
	void confirm_Request(string tn)
	{
		FL.AddFriend(tn);
		friend_request.UnFriend(tn);
	}
	void DiplayFrinds()
	{
		FL.displayfriendLIst();
	}
	void DisplayPending()
	{
		friend_request.displayfriendLIst();
	}
	void Friends_Post()
	{

	}
	Frnd* GetFriendListHead()
	{
		return FL.GetHead();
	}
};

class TreeNode
{
	User data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode()
	{
		left = NULL;
		right = NULL;
	}
	void setUser(User temp)
	{
		data = temp;
	}
	void setLeft(TreeNode* l)
	{
		left = l;
	}
	void setRight(TreeNode* r)
	{
		right = r;
	}
	User getUser()
	{
		return data;
	}
	TreeNode* getLeft()
	{
		return left;
	}
	TreeNode* getRight()
	{
		return right;
	}
	void DisplayUserPOST()
	{
		data.DisplayPosts();
	}
	void DisplayUserComment(int i)
	{
		data.diplayComments(i);
	}
	void UpdateUserPost(int i)
	{
		data.UpdatePost(i);
	}
	void DeleteUserPost(string tn, int i)
	{
		data.DeletePost(tn, i);
	}
	void AddUserPost(Post temp)
	{
		data.addPost(temp);
	}
	void DisplayUserOnly()
	{
		data.DisplayUser();
	}
	void AddComment(int i, Comment c)
	{
		data.AddC(i, c);
	}
	void UpdateComment(string tn, int i)
	{
		data.UpdateC(tn, i);
	}
	void DelComment(string tn, int i)
	{
		data.DelC(tn, i);
	}
};

class BST
{
	TreeNode* Root;
public:
	BST()
	{
		Root = NULL;
	}
	TreeNode* getRoot()
	{
		return Root;
	}
	void Insert(User val)
	{
		TreeNode* N = new TreeNode;
		N->setUser(val);
		if (Root == NULL)
		{
			Root = N;
			return;
		}
		TreeNode* temp = Root;
		while (true)
		{
			if (N->getUser().getUserName() < temp->getUser().getUserName())
			{
				if (temp->getLeft() == NULL)
				{
					temp->setLeft(N);
					return;
				}
				temp = temp->getLeft();
			}
			else
			{
				if (temp->getRight() == NULL)
				{
					temp->setRight(N);
					return;
				}
				temp = temp->getRight();
			}
		}
	}
	void DisplayPre(TreeNode* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		temp->DisplayUserOnly();
		DisplayPre(temp->getLeft());
		DisplayPre(temp->getRight());
	}
	void DisplayIn(TreeNode* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		DisplayIn(temp->getLeft());
		temp->DisplayUserOnly();
		DisplayIn(temp->getRight());
	}
	void DisplayPost(TreeNode* temp)
	{
		if (temp == NULL)
		{
			return;
		}
		DisplayPost(temp->getLeft());
		DisplayPost(temp->getRight());
		temp->DisplayUserOnly();
	}
	TreeNode* Search(string val)
	{
		TreeNode* temp = Root;
		if (Root == NULL)
		{
			return NULL;
		}
		while (temp != NULL)
		{
			if (temp->getUser().getUserName() == val)
			{
				return temp;
			}
			else if (val < temp->getUser().getUserName())
			{
				temp = temp->getLeft();
			}
			else
			{
				temp = temp->getRight();
			}
		}
		return NULL;
	}
	int countItems(TreeNode* temp, int n)
	{
		if (temp == NULL)
		{
			return n;
		}
		n++;
		n = countItems(temp->getLeft(), n);
		return countItems(temp->getRight(), n);
	}
	void Delete(string key)
	{
		bool flag = false;
		TreeNode* temp = Root;
		TreeNode* p = Root;
		if (Root == NULL)
		{
			cout << "Tree is Empty..." << endl;
			return;
		}
		while (temp != NULL)
		{
			if (temp->getUser().getUserName() == key)
			{
				flag = true;
				break;
			}
			else if (key < temp->getUser().getUserName())
			{
				p = temp;
				temp = temp->getLeft();
			}
			else
			{
				p = temp;
				temp = temp->getRight();
			}
		}
		if (flag)
		{
			if ((temp->getRight() == NULL) && (temp->getLeft() == NULL))
			{
				if (temp == Root)
				{
					Root = NULL;
				}
				else if (p->getRight() == temp)
				{
					p->setRight(NULL);
				}
				else
				{
					p->setLeft(NULL);
				}
				delete temp;
			}
			else if ((temp->getLeft() != NULL) && (temp->getRight() != NULL))
			{
				TreeNode* M = FindMax(temp->getLeft());
				TreeNode* MP = FindParent(M->getUser().getUserName());
				temp->setUser(M->getUser());
				if (MP != temp)
				{
					MP->setRight(M->getLeft());
				}
				else
				{
					MP->setLeft(M->getLeft());
				}
				M->setLeft(NULL);
				delete M;
			}
			else
			{
				if (temp->getRight() != NULL)
				{
					if (temp == Root)
					{
						Root = temp->getRight();
					}
					else if (p->getLeft() == temp)
					{
						p->setLeft(temp->getRight());
					}
					else
					{
						p->setRight(temp->getRight());
					}
					temp->setRight(NULL);
					delete temp;
				}
				else
				{
					if (temp == Root)
					{
						Root = temp->getLeft();
					}
					else if (p->getLeft() == temp)
					{
						p->setLeft(temp->getLeft());
					}
					else
					{
						p->setRight(temp->getLeft());
					}
					temp->setLeft(NULL);
					delete temp;
				}
			}
		}
		else
		{
			cout << "Value Not Found...." << endl;
		}
	}
	TreeNode* FindMax(TreeNode* temp)
	{
		while (temp->getRight() != NULL)
		{
			temp = temp->getRight();
		}
		return temp;
	}
	TreeNode* FindParent(string key)
	{
		bool flag = false;
		TreeNode* temp = Root;
		TreeNode* p = Root;
		if (Root == NULL)
		{
			cout << "Tree is Empty..." << endl;
			return NULL;
		}
		while (temp != NULL)
		{

			if (temp->getUser().getUserName() == key)
			{
				flag = true;
				break;
			}
			else if (key < temp->getUser().getUserName())
			{
				p = temp;
				temp = temp->getLeft();
			}
			else
			{
				p = temp;
				temp = temp->getRight();
			}
		}
		if (flag)
		{
			if (temp == Root)
			{
				return Root;
			}
			else
			{
				return p;
			}
		}
		else
		{
			return NULL;
		}
	}
};

class Hash
{
	int bucketSize;;
	BST* bucket;
	Tries User_Tree;
public:
	Hash(int b)
	{
		bucketSize = b;
		bucket = new BST[bucketSize];
	}
	int hashFunction(string s)
	{
		int num = 0;
		for (int i = 0; i < s.length(); i++)
		{
			num += s[i];
		}
		return (num % bucketSize);
	}
	void insertUser(User u)
	{
		int index = hashFunction(u.getUserName());
		bucket[index].Insert(u);
		User_Tree.Insert(u.getUserName());
	}
	void deleteUser(string uname)
	{
		int index = hashFunction(uname);
		bucket[index].Delete(uname);
	}
	TreeNode* searchUser(string uname)
	{
		int index = hashFunction(uname);
		return bucket[index].Search(uname);
	}
	void displayHash()
	{
		for (int i = 0; i < bucketSize; i++)
		{
			cout << "Tree " << i << endl;
			bucket[i].DisplayIn(bucket[i].getRoot());
			cout << endl;
		}
	}
	void DisplayUserPost(string tn)
	{
		TreeNode* temp = searchUser(tn);
		temp->DisplayUserPOST();
	}
	void DisplayUserComments(string tn, int i)
	{
		TreeNode* temp = searchUser(tn);
		temp->DisplayUserComment(i);
	}
	void AddUserPost(string tn, Post p)
	{
		TreeNode* temp = searchUser(tn);
		temp->AddUserPost(p);
	}
	void UpdatUserPost(string tn, int i)
	{
		TreeNode* temp = searchUser(tn);
		temp->UpdateUserPost(i);
	}
	void DeleteUserPost(string tn, int i)
	{
		TreeNode* temp = searchUser(tn);
		temp->DeleteUserPost(tn, i);
	}
	void AddUserComment(string tn, int i, Comment C)
	{
		TreeNode* temp = searchUser(tn);
		temp->AddComment(i, C);
	}
	void UpdateUserComment(string tn, int i)
	{
		TreeNode* temp = searchUser(tn);
		temp->UpdateComment(tn, i);
	}
	void DeleteComment(string tn, int i)
	{
		TreeNode* temp = searchUser(tn);
		temp->DelComment(tn, i);
	}
	void unFriend(string tname, string f_name)
	{
		TreeNode* temp = searchUser(tname);
		temp->getUser().UnFriend(f_name);
		TreeNode* t = searchUser(f_name);
		t->getUser().UnFriend(tname);
	}
	void Send_Friend_Request(string tn, string key)
	{
		string k;
		TreeNode* temp = searchUser(tn);
		cout << "SUGGESTIONS ARE..." << endl;
		Node* temp1 = User_Tree.search(User_Tree.root, key, 0);
		key.erase(key.size() - 1);
		if (temp)
		{
			User_Tree.Display(temp1, key);
		}
		else
		{
			cout << "Not Found";
		}
		cout << "ENTER THE NAME YOU WANT TO ENTER...!";
		getline(cin, k);
		Node* temp2 = User_Tree.search(User_Tree.root, k, 0);
		if (temp2 != NULL)
		{
			temp->getUser().addFriend_request(k);
			TreeNode* t = searchUser(k);
			t->getUser().addFriend_request(tn);
		}
		else
		{
			cout << "THIS FRIEND DOESNOT OCCUR\n";
		}
	}
	void ConfirmREQUEST(string f_name, string m_name)
	{
		TreeNode* t1 = searchUser(f_name);
		TreeNode* t2 = searchUser(m_name);
		t2->getUser().confirm_Request(f_name);
		t1->getUser().confirm_Request(m_name);
	}
	void DisplayPendingRequest(string tname)
	{
		TreeNode* t1 = searchUser(tname);
		cout << "\t\t\t\t\t\tPENDING REQUESTS\n";
		t1->getUser().DiplayFrinds();
	}
	void DisplayFriendList(string tname)
	{
		TreeNode* t1 = searchUser(tname);
		cout << "\t\t\t\t\t\tMY FRIENDS\n";
		t1->getUser().DiplayFrinds();
	}
	void sendMessage(string mname, string fname)    
	{
		viewConversation(mname, fname);
		cout << endl;
		int year, month, day, hour, min, sec;
		time_t now;
		Time t1;
		Date d1;
		struct  tm* ti;
		time(&now);
		ti = localtime(&now);
		year = 1900 + ti->tm_year;
		month = 1 + ti->tm_mon;
		day = ti->tm_mday;
		hour = ti->tm_hour;
		min = ti->tm_min;
		sec = ti->tm_sec;
		d1.setDay(day);
		d1.setMonth(month);
		d1.setYear(year);
		t1.setTime(hour, min, sec);
		Message msg;                        
		string str;
		TreeNode* f = searchUser(fname);
		TreeNode* m = searchUser(mname);
		cout << "Enter Message : ";
		getline(cin, str);
		msg.setMText(str);
		msg.setMDate(d1);
		msg.setMTime(t1);
		f->getUser().getFriendList().getFriend(mname)->Add_Message(msg);
		m->getUser().getFriendList().getFriend(fname)->Add_Message(msg);
	}
	void viewConversation(string mn, string fn)   
	{
		TreeNode* m = searchUser(mn);
		m->getUser().getFriendList().getFriend(fn)->View_Chat();
	}
	void Friends_Post(string tname)
	{
		Frnd *f;
		string t_name;
		TreeNode* t1 = searchUser(tname);
		f = t1->getUser().GetFriendListHead();
		while (f != NULL)
		{
			tname = f->getFriendName();
			DisplayUserPost(tname);
		}

	}
};

void Afterlogin()
{
	cout << "\n\n\n\n\n";
	cout << "\t1-> PERSONAL TAB\t\t\t2-> HOME TAB\t\t\t3->FRIEND TAB\t\t\t4->MESSAGES\t\t\t5->LOGOUT\n";

}
void PersonalTab()
{
	cout << "\n\n\n\n\n";
	cout << "\t\t\t\t1->VIEW POST\n";
	cout << "\t\t\t\t2->VIEW COMMENTS\n";
	cout << "\t\t\t\t3->ADD POST\n";
	cout << "\t\t\t\t4->DELETE POST\n";
	cout << "\t\t\t\t5->UPDATE POST\n";
	cout << "\t\t\t\t6->ADD COMMENT\n";
	cout << "\t\t\t\t7->UPDATE COMMENT\n";
	cout << "\t\t\t\t8->DELETE COMMENT\n";
	cout << "\t\t\t\t9->BACK TO MAIN\n";
}
void HomeTab()
{
	cout << "\n\n\n\n\n";
	cout << "\t\t\t\t1->VIEW FRIENDS POSTS\n";
	cout << "\t\t\t\t2->VIEW COMMENTS\n";
	cout << "\t\t\t\t3->ADD POST\n";
	cout << "\t\t\t\t4->BACK TO MAIN\n";
}
void FriendTab()
{
	cout << "\n\n\n\n\n";
	cout << "\t\t\t\t1->MY FRIENDS\n";
	cout << "\t\t\t\t2->ADD FRIEND\n";
	cout << "\t\t\t\t3->FRIEND REQUESTS\n";
	cout << "\t\t\t\t4->BACK TO MAIN\n";
}
void MessageTab()
{
	cout << "\n\n\n\n\n";
	cout << "\t\t\t\t1->VIEW CONVERSATION\n";
	cout << "\t\t\t\t2->BACK TO MAIN\n";
}
void ConvoTab()
{
	cout << "\n\n\n\n\n";
	cout << "\t\t\t\t1->SEND MESSAGE\n";
	cout << "\t\t\t\t2->BACK TO MAIN\n";
}
void main()
{
	int year;
	int month;
	int day;
	int min, hour, sec;
	Comment c;
	Post p;
	Date d1;
	Time t1;
	string PostText;
	string PostOwner;
	string  Commenttext;
	string CommentOwner;
	int personal_choice;
	int home_choice;
	int msg_choice;
	int conv_choice;
	string no,Fname;
	Hash social(3);
	User u;
	TreeNode* tempuser;
	int ch1;
	int ch2;
	do
	{
		int choice;
		string Uname, mob, name;
		string pass = "";
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "\t\t\t|       | |`` |        + + +    * *   |+     +| |``         * * * * * *    * *          |```  |* * *    " << endl;
		cout << "\t\t\t|       | |      |      +        *     * | +   + | |                   |       *     *        |        |      *  " << endl;
		cout << "\t\t\t|   +   | |---   |     +         *     * |   +   | |---                |       *     *        |```  |* * *    " << endl;
		cout << "\t\t\t|  +  + | |      |      +        *     * |       | |                   |       *     *        |        |      *  " << endl;
		cout << "\t\t\t|+     +| |__ |__   + + +    * *   |       | |___              |         * *          |        |* *  *   " << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "\t\t\t\t\t1. SIGN IN." << endl << endl;
		cout << "\t\t\t\t\t2. CREATE AN ACCOUNT." << endl << endl;
		cout << "\t\t\t\t\t3. CLOSE APP." << endl << endl;
		cout << "\t\t\t\t\tENTER YOUR CHOICE : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			char ch;
			system("cls");
			cin.ignore();
			cout << "\t\t\t\t\t\t\t\tSIGN IN PORTAL" << endl << endl << endl;
			cout << "\t\t\t\t\t\t\tENTER USERNAME : ";
			getline(cin, Uname);
			while (!social.searchUser(Uname))
			{
				cout << "\t\t\t\t\t\t\tINVALID USERNAME..!!" << endl;
				cout << "\t\t\t\t\t\t\tENTER AGAIN....! : ";
				getline(cin, Uname);
				cout << "\t\t\t\t\t\t\tDo YOU HAVE AN ACCOUNT (Y/N) : ";
				cin >> ch;
				while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
				{
					cout << "\t\t\t\t\t\t\tINVALID ..!!" << endl;
					cout << "\t\t\t\t\t\t\tDo YOU HAVE AN ACCOUNT (Y/N) : ";
					cin >> ch;
					cout << "\n";
				}
				if (ch == 'Y' || ch == 'y')
				{
					cout << "\t\t\t\t\t\t\tENTER AGAIN....! : ";
					getline(cin, Uname);
				}
				if (ch == 'N' || ch == 'n')
				{
					goto NewACC;
				}
			}
			tempuser = social.searchUser(Uname);
			cout << "\t\t\t\t\t\t\tENTER PASSWORD : ";
			while (ch1 = _getch())
			{
				if (ch1 == 13)
				{
					break;
				}
				else if (ch1 == 8)
				{
					if (pass.length() > 0)
					{
						cout << "\b \b";
						pass.erase(pass.length() - 1);
					}
				}
				else
				{
					cout << "*";
					pass += ch1;
				}
			}
			cout << "\n";
			while (tempuser->getUser().getPassword() != pass)
			{
				cout << "\t\t\t\t\t\t\tINCORRECT PASSWORD..!!" << endl;
			lab:
				cout << "\t\t\t\t\t\t\tENTER AGAIN..!!\n";
				while (ch1 = _getch())
				{
					if (ch1 == 13)
					{
						break;
					}
					else if (ch1 == 8)
					{
						if (pass.length() > 0)
						{
							cout << "\b \b";
							pass.erase(pass.length() - 1);
						}
					}
					else
					{
						cout << "*";
						pass += ch1;
					}
				}
				cout << "\n";
				cin.ignore();
				/*cout << "HAVE YOU FORGOTTEN YOUR PASSWORD (Y/N) : ";
				cin >> ch;
				while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
				{
					cout << "INVALID INPUT...!\n";
					cout << "HAVE YOU FORGOTTEN YOUR PASSWORD (Y/N) : ";
					cin >> ch;
				}
				if (ch == 'Y' || ch == 'y')
				{
					goto retrivePass;
				}
				if (ch == 'N' || ch == 'n')
				{
					goto lab;
				}*/
			}
			cout << "\n\n\n\n";
			cout << "\t\t\t\t\t\t\t\tSUCCESSFULL LOGIN\n";
			system("cls");
			cout << "HELLO " << tempuser->getUser().getName() << "   :)  " << "\n";
			cout << "WELCOME TO FACEBOOK PORTAL......\n";
			u = tempuser->getUser();
		lab1:
			Afterlogin();
			cout << "\n\n\n";
			cout << "\t\t\t\t\t\t\tENTER YOUR CHOICE...:\n";
			cin >> choice;
			while (choice > 5 || choice < 1)
			{
				cout << "\t\t\t\t\t\t\tINVALID INPUT...!\n";
				cout << "\t\t\t\t\t\t\tENTER AGAIN...:";
				cin >> choice;
			}
			system("cls");
			cout << "HELLO " << tempuser->getUser().getName() << "   :)  " << "\n";
			cout << "WELCOME TO FACEBOOK PORTAL......\n";
			if (choice == 1)
			{
			P:
				PersonalTab();
				cout << "\t\t\t\t\t\t\tENTER YOUR CHOICE...:\n";
				cin >> personal_choice;
				while (personal_choice > 6 || personal_choice < 1)
				{
					cout << "\t\t\t\t\t\t\tINVALID INPUT...!\n";
					cout << "\t\t\t\t\t\t\tENTER AGAIN...:";
					cin >> personal_choice;
				}
				if (personal_choice == 1)
				{
					PostOwner = u.getUserName();
					cout << "\t\t\t\t\t\t\tPOSTS\n";
					social.DisplayUserPost(PostOwner);
					goto P;
				}
				else if (personal_choice == 2)
				{
					PostOwner = u.getUserName();
					social.DisplayUserPost(PostOwner);
					int n;
					int t;
					t = u.getPostN();
					cout << "\t\t\t\t\t\t\tENTER POST NUMBER TO SEE ALL COMMENTS : ";
					cin >> n;
					if (n > t)
					{
						cout << "\t\t\t\t\t\t\tINVALID INPUT...!\n";
						cout << "\t\t\t\t\t\t\tENTER AGAIN...\n";
						cin >> n;
					}
					cout << "\t\t\t\t\t\t\tCOMMENTS ON POST " << n << '\n';
					social.DisplayUserComments(u.getUserName(), n);
					goto P;
				}
				else if (personal_choice == 3)
				{
					cout << "\t\t\t\t\t\t\tADD POST\n";
					PostOwner = u.getUserName();
					cin.ignore();
					cout << "ENTER TEXT : ";
					getline(cin, PostText);
					time_t now;

					struct  tm* ti;
					time(&now);
					ti = localtime(&now);
					year = 1900 + ti->tm_year;
					month = 1 + ti->tm_mon;
					day = ti->tm_mday;
					hour = ti->tm_hour;
					min = ti->tm_min;
					sec = ti->tm_sec;
					d1.setDay(day);
					d1.setMonth(month);
					d1.setYear(year);
					t1.setTime(hour, min, sec);
					p.setPost(PostOwner, PostText, t1, d1);
					u = tempuser->getUser();
					social.AddUserPost(u.getUserName(), p);
					goto P;
				}
				else if (personal_choice == 4)
				{
					social.DisplayUserPost(u.getUserName());
					int n;
					int t;
					t = u.getPostN();
					cout << "\t\t\t\t\t\t\tENTER POST NUMBER YOU WANT TO DELETE : ";
					cin >> n;
					if (n > t)
					{
						cout << "\t\t\t\t\t\t\tINVALID INPUT...!\n";
						cout << "\t\t\t\t\t\t\tENTER AGAIN...\n";
						cin >> n;
					}
					PostOwner = u.getUserName();
					social.DeleteUserPost(PostOwner, n);
					goto P;
				}
				else if (personal_choice == 5)
				{
					social.DisplayUserPost(u.getUserName());
					int n;
					int t;
					t = u.getPostN();
					cout << "\t\t\t\t\t\t\tENTER POST NUMBER YOU WANT TO UPDATE : ";
					cin >> n;
					if (n > t)
					{
						cout << "\t\t\t\t\t\t\tINVALID INPUT...!\n";
						cout << "\t\t\t\t\t\t\tENTER AGAIN...\n";
						cin >> n;
					}
					cin.ignore();
					social.UpdatUserPost(u.getUserName(), n);
					goto P;
				}
				else if (personal_choice == 6)
				{
					int n;
					int t;
					social.DisplayUserPost(u.getUserName());
					t = u.getPostN();
					cout << "\t\t\t\t\t\t\tENTER POST NUMBER ON WHICH YOU WANT TO COMMENT : ";
					cin >> n;
					if (n > t)
					{
						cout << "\t\t\t\t\t\t\tINVALID INPUT...!\n";
						cout << "\t\t\t\t\t\t\tENTER AGAIN...\n";
						cin >> n;
					}
					CommentOwner = u.getUserName();
					cin.ignore();
					cout << "ENTER TEXT : ";
					getline(cin, Commenttext);
					time_t now;

					struct  tm* ti;
					time(&now);
					ti = localtime(&now);
					year = 1900 + ti->tm_year;
					month = 1 + ti->tm_mon;
					day = ti->tm_mday;
					hour = ti->tm_hour;
					min = ti->tm_min;
					sec = ti->tm_sec;
					d1.setDay(day);
					d1.setMonth(month);
					d1.setYear(year);
					t1.setTime(hour, min, sec);
					c.seCtDate(d1);
					c.setCName(CommentOwner);
					c.setCText(Commenttext);
					c.setCTime(t1);
					social.AddUserComment(u.getUserName(), n, c);
					goto P;
				}
				else if (personal_choice == 7)
				{
					social.DisplayUserPost(u.getUserName());
					int n;
					int t;
					t = u.getPostN();
					cout << "\t\t\t\t\t\t\tENTER POST NUMBER ON WHICH OU WANT TO DELETE THE COMMENT : ";
					cin >> n;
					if (n > t)
					{
						cout << "\t\t\t\t\t\t\tINVALID INPUT...!\n";
						cout << "\t\t\t\t\t\t\tENTER AGAIN...\n";
						cin >> n;
					}
					social.DisplayUserComments(u.getUserName(), n);

				}
				else if (personal_choice == 8)
				{
					social.DisplayUserPost(u.getUserName());
					int n;
					int t;
					t = u.getPostN();
					cout << "\t\t\t\t\t\t\tENTER POST NUMBER ON WHICH OU WANT TO DELETE THE COMMENT : ";
					cin >> n;
					if (n > t)
					{
						cout << "\t\t\t\t\t\t\tINVALID INPUT...!\n";
						cout << "\t\t\t\t\t\t\tENTER AGAIN...\n";
						cin >> n;
					}
					goto P;
				}
				else if (personal_choice == 9)
				{
				goto lab1;
                }
			}
			if (choice == 2)
			{
				cout << "\t\t\t\t\t\t\t\t\tHOME TAB\n";
				HomeTab();
				cout << "\t\t\t\t\t\tENTER YOUR CHOICE...";
				cin >> home_choice;
				cout << "\n\n\n";
				while (home_choice > 4 || home_choice < 1)
				{
					cout << "\t\t\t\tINVALID INPUT\n";
					cout << "\t\t\t\t\t\tENTER AGAIN....";
					cin >> home_choice;
				}
				if (home_choice == 1)
				{
					social.Friends_Post(u.getUserName());
				}

			}
			if (choice == 3)
			{
				FriendTab();
			}
			if (choice == 4)
			{
				M:
				MessageTab();
				cout << "\t\t\t\t\t\t\tENTER YOUR CHOICE...:\n";
				cin >> msg_choice;
				while (msg_choice > 2 || msg_choice < 1)
				{
					cout << "\t\t\t\t\t\t\tINVALID INPUT...!\n";
					cout << "\t\t\t\t\t\t\tENTER AGAIN...:";
					cin >> msg_choice;
				}
				if (msg_choice == 1)
				{
					Con:
					ConvoTab();
					cout << "\t\t\t\t\t\t\tENTER YOUR CHOICE...:\n";
					cin >> conv_choice;
					while (msg_choice > 3 || msg_choice < 1)
					{
						cout << "\t\t\t\t\t\t\tINVALID INPUT...!\n";
						cout << "\t\t\t\t\t\t\tENTER AGAIN...:";
						cin >> conv_choice;
					}
					if (conv_choice == 1)
					{
						social.DisplayFriendList(u.getUserName());
						cout << "Enter Friend Name : ";
						getline(cin, Fname);
						social.sendMessage(u.getUserName(), Fname);
						goto Con;
					}
					else if (conv_choice == 2)
					{
						goto M;
					}

				}
				else if (msg_choice == 2)
				{
					goto lab1;
				}
			}

			/*	retrivePass:

					cout << "ENTER YOUR PHONE NUMBER TO RETRIEVE YOUR ACCOUNT..!\n";
					getline(cin, no);
					while (tempuser->getUser().getPhNum() != no)
					{
						cout << "THIS PHONE NUMBER IS NOT FOUND..!!\n";
						cout << "ENTER AGAIN...!\n";
						getline(cin, no);
						cout << "HAVE YOU FORGOTTEN YOUR PHONE NUMBER (Y/N) : ";
						cin >> ch;
						while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
						{
							cout << "INVALID INPUT..!\n";
							cout << "HAVE YOU FORGOTTEN YOUR PHONE NUMBER (Y/N) : ";
							cin >> ch;
						}
						if (ch == 'Y' || ch == 'y')
						{
							cout << "CREATE NEW ACCOUNT THEN..!\n";
							goto NewACC;
						}
						if (ch == 'N' || ch == 'n')
						{
							cout << "ENTER YOUR PHONE NUMBER TO RETRIEVE YOUR ACCOUNT..!\n";
							getline(cin, no);
						}
					}*/
		NewACC:
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			cin.ignore();
			cout << "\n\n\n\n\n";
			cout << "\t\t\t\t\t\t\t\tSIGN UP PORTAL" << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t\tENTER NAME : ";
			getline(cin, name);
			u.setName(name);
			cout << "\t\t\t\t\t\t\tENTER MOBILE NUMBER # : ";
			getline(cin, mob);
			u.setPhNum(mob);
			cout << "\t\t\t\t\t\t\tENTER USERNAME : ";
			getline(cin, Uname);
			cout << "\n";
			while (social.searchUser(Uname))
			{
				cout << "\t\t\t\t\t\t\tUSERNAME ALREADY TAKEN....." << endl;
				cout << "\t\t\t\t\t\t\tENTER AGAIN.. : ";
				getline(cin, Uname);
			}
			u.setUserName(Uname);
			cout << "\t\t\t\t\t\t\tENTER PASSWORD : ";
			while (ch2 = _getch())
			{
				if (ch2 == 13)
				{
					break;
				}
				else if (ch2 == 8)
				{
					if (pass.length() > 0)
					{
						cout << "\b \b";
						pass.erase(pass.length() - 1);
					}
				}
				else
				{
					cout << "*";
					pass += ch2;
				}
			}
			u.setPassword(pass);
			social.insertUser(u);
			cout << endl << endl << "\t\t\t\t\t\t\tACCOUNT CREATED SUCCESSFULLY...." << endl << endl;
			system("cls");
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << endl << endl << "\t\t\t\t\t\t\tTHANK YOU FOR COMMING..." << endl << endl;
			system("pause");
			exit(0);
		}
		}
	} while (true);

}