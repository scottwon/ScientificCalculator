#include<iostream>
#include<iomanip>
#include<cmath>
#define debug
using namespace std;
template<typename T>class stack{//�Զ���ջ��һ��������һ���������ڴ�ռ䣬��ջ���ʱ��������һ���µĽڵ� 
private:
	static const int BLOCKSIZE=1024;
	template<typename S>struct stackNode{
		S data[BLOCKSIZE];//��˳���Ϊ�ڵ������ 
		stackNode<S>* next;
		stackNode<S>* prev;
	};
	stackNode<T>* node;
	T* top;
public:
	stack(){//���캯�� 
		node=new stackNode<T>;
		node->next=NULL;
		node->prev=NULL;
		top=(node->data)-1;
	}
	~stack(){//�������� 
		stackNode<T>* ptr;
		while(node!=NULL){
			ptr=node;
			node=node->prev;
			delete ptr;
		}
	}
	void push(const T& x){//��ջ���� 
		if(top-(node->data)==BLOCKSIZE-1){//����˳�����������£�����һ���µ�˳���ڵ� 
			node->next=new stackNode<T>;
			node->next->prev=node;
			node->next->next=NULL;
			node=node->next;
			top=node->data;
		}
		else{//�������ͬ��ͨջ 
			++top;
		}
		*top=x;
	}
	T pop(){//��ջ��Ԫ�ص��� 
		T x=*top;
		if(top==(node->data)&&node->prev!=NULL){//ǡ��β�ڵ�Ϊ��ʱ��ɾ���ڵ� 
			node=node->prev;
			delete node->next;
			node->next=NULL;
			top=(node->data)+BLOCKSIZE-1;
		}
		else{//�������ͬ��ͨջ 
			--top;
		}
		return x;
	}
	T* Top(){//����ջ��Ԫ�� 
		return top;
	}
	bool isEmpty(){//�ж�ջ�Ƿ�Ϊ�� 
		if(top==(node->data)-1&&node->prev==NULL)return true;
		return false;
	}
};

template<typename T>class queue{//�Զ�����У�Ҳ����˳�����Ϊ�ڵ㹹�ɵ�����ʵ�ֵ� 
private:
	static const int BLOCKSIZE=1024;
	template<typename S>struct queueNode{//˳���ڵ�Ķ��� 
		S data[BLOCKSIZE];
		queueNode<S>* prev;
		queueNode<S>* next;
	};
	queueNode<T>* frontNode;
	queueNode<T>* tailNode;
	T* frontPtr;
	T* tailPtr;
public:
	queue(){//���캯�� 
		tailNode=new queueNode<T>;
		frontNode=tailNode;
		tailNode->prev=NULL;
		tailNode->next=NULL;
		frontPtr=(frontNode->data)-1;
		tailPtr=(tailNode->data)-1;
	}
	~queue(){//�������� 
		queueNode<T>* ptr;
		while(tailNode!=NULL){
			ptr=tailNode;
			tailNode=tailNode->prev;
			delete ptr;
		}
	}
	void push(const T& x){//��Ӻ��� 
		if(tailPtr-(tailNode->data)==BLOCKSIZE-1){//�������ڴ�ռ����� 
			tailNode->next=new queueNode<T>;
			tailNode->next->prev=tailNode;
			tailNode->next->next=NULL;
			tailNode=tailNode->next;
			tailPtr=tailNode->data;
		}
		else{
			if(tailPtr==(frontNode->data)-1){
				++frontPtr;
			}
			++tailPtr;
		}
		*tailPtr=x;
	}
	T pop(){//���Ӻ��� 
		if(frontPtr==(tailNode->data)-1)return NULL;//�ն��� 
		T x=*frontPtr;
		if(frontPtr==tailPtr){//����ֻ��һ��Ԫ�� 
			frontPtr=(frontNode->data)-1;
			tailPtr=(tailNode->data)-1;
		}
		else if(frontPtr-(frontNode->data)==BLOCKSIZE-1){//��ȡ���ڵ����� 
			frontNode=frontNode->next;
			delete frontNode->prev;
			frontNode->prev=NULL;
			frontPtr=frontNode->data;
		}
		else{
			++frontPtr;
		}
		return x;
	}
	bool isEmpty(){//�ж϶����Ƿ�Ϊ�� 
		if(tailNode->prev==NULL&&tailPtr==(tailNode->data)-1)return true;
		return false;
	}
};

//Ϊ�ṩ����ָ�룬��ʵ�ּ����������õ���һЩ������������ 
double Add(double a,double b){
	return a+b;
}
double Minus(double a,double b){
	return a-b;
}
double Multiply(double a,double b){
	return a*b;
}
double Divide(double a,double b){
	return a*1.0/b;
}
int Mod(int a,int b){//ȡģ 
	return a%b;
}
int Factorial(int a){//�׳� 
	if(a<=0){
		return 1;
	}
	else{
		return a*Factorial(a-1);
	}
}
double Sum(double a[],int n){//��� 
	double sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	return sum;
}
double Average(double a[],int n){//��ƽ�� 
	double sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	return sum*1.0/n;
}
double Var(double a[],int n){//���������� 
	double sum=0;
	double sqSum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		sqSum+=a[i]*a[i];
	}
	return sqSum/(n-1)-sum*sum/(n*(n-1));
}
double Sd(double a[],int n){//��������׼�� 
	double sum=0;
	double sqSum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		sqSum+=a[i]*a[i];
	}
	return sqrt(sqSum/(n-1)-sum*sum/(n*(n-1)));
}
double Fail(double a,double b){//�Զ����Fail����������ʧ��ʱ���غ���Fail����ָ���term���� 
	return -1;
}

//�������ı�����ʱ�õ����ַ������������ 
bool isNumber(char ch){//�Ƿ������� 
	if(ch>='0'&&ch<='9')return true;
	return false;
}
bool isAlphabet(char ch){//�Ƿ�����ĸ 
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))return true;
	return false;
}
bool isOperator(char ch){//�Ƿ�������� 
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='!'||ch=='%')return true;
	return false;
}


const int precision=10;//������������������ 
bool equal(double a,double b){//���帡��������������ȵ���ֵ 
	if(abs(a-b)<=0.000000000001)return true;
	return false;
}

char* substr(char* ch,int begin,int end){//���ڹ������ַ��� 
	char* subCh;
	if(end-begin-1>0){//����������������������һ���ַ� 
		subCh=new char[end-begin];
		for(int i=0;i<end-begin-1;i++){
			subCh[i]=ch[begin+i+1];
		}
		subCh[end-begin-1]='\0';
	}
	else{//������ 
		subCh=new char[1];
		subCh[0]='\0';
	}
	return subCh;
}
const int nameLength=10;//���庯�����Ƶĳ������� 

void tagCopy(char* dest,char* src,int n=nameLength){//�ַ������ƣ�����function�����Ĺ��죬���������ַ������Ƹ�function��ĳ�Աtag 
	for(int i=0;i<n-1;i++){
		dest[i]=src[i];
	}
	dest[n-1]='\0';
}

//�������� 
class calculator{
private:
	struct errorInfo{//������Ϣ�ṹ�壬��������Ķ�λ����� 
		int position;
		int errCode;
	};
	struct term{//��������������Ľṹ�� 
		union{
			int ival;//���α��� 
			double dval;//�����ͱ��� 
			double(*ptr1)(double,double);//�������͵ĺ���ָ�� 
			double(*ptr2)(double);
			int(*ptr3)(int,int);
			int(*ptr4)(int);
			double(*ptr5)(double*,int);//�������������ĺ��� 
		}val;
		enum{//����term�������� 
			Int,Float,biDouble,uniDouble,biInt,uniInt,Array
		}attribute;
		enum{//����������Ӧ�����ıߵĲ��������н�ϣ����ڲ�����������ΪNone 
			None,L,R,LR,RR
		}category;
		int position;//����������������ַ����е�λ�� 
		void print(){//��ӡterm�������Ϣ 
			switch(attribute){
				case Int:
					cout<<val.ival;
					break;
				case Float:
					cout<<setprecision(precision)<<val.dval;
					break;
				case biDouble:
					if(val.ptr1==Add){
						cout<<'+';
					}
					else if(val.ptr1==Minus){
						cout<<'-';
					}
					else if(val.ptr1==Multiply){
						cout<<'*';
					}
					else if(val.ptr1==Divide){
						cout<<'/';
					}
					else if(val.ptr1==pow){
						cout<<"pow";
					}
					else if(val.ptr1==Fail){
						cout<<"Error";
					}
					break;
				case uniDouble:
					if(val.ptr2==fabs){
						cout<<"abs";
					}
					else if(val.ptr2==acos){
						cout<<"acos";
					}
					else if(val.ptr2==asin){
						cout<<"asin";
					}
					else if(val.ptr2==atan){
						cout<<"atan";
					}
					else if(val.ptr2==cos){
						cout<<"cos";
					}
					else if(val.ptr2==exp){
						cout<<"exp";
					}
					else if(val.ptr2==log){
						cout<<"ln";
					}
					else if(val.ptr2==log10){
						cout<<"log";
					}
					else if(val.ptr2==sqrt){
						cout<<"sqrt";
					}
					else if(val.ptr2==sin){
						cout<<"sin";
					}
					else if(val.ptr2==tan){
						cout<<"tan";
					}
					break;
				case biInt:
					if(val.ptr3==Mod){
						cout<<'%';
					}
					break;
				case uniInt:
					if(val.ptr4==Factorial){
						cout<<'!';
					}
					break;
				case Array:
					if(val.ptr5==Sum){
						cout<<"sum";
					}
					else if(val.ptr5==Average){
						cout<<"avg";
					}
					else if(val.ptr5==Var){
						cout<<"var";
					}
					else if(val.ptr5==Sd){
						cout<<"SD";
					}
				default:
					cout<<"Error";
			}
		}
	};

	struct termNode{//termList˫������Ľڵ� 
		term data;
		termNode* prev;
		termNode* next;
	};

	struct termList{//��term��Ϊ����Ԫ�ص�˫������ 
		termNode* front;
		termNode* tail;
		unsigned int count;
		termList(){//���캯�� 
			front=NULL;
			tail=NULL;
			count=0;
		}
		~termList(){//�������� 
			termNode* p;
			while(tail!=NULL){
				p=tail;
				tail=tail->prev;
				delete p;
			}
		}
		void push(const term& x){//���µ�term��������β 
			if(tail==NULL){//���ڿ��������� 
				tail=new termNode;
				tail->data=x;
				front=tail;
				tail->prev=NULL;
				tail->next=NULL;
			}
			else{//�ǿ����� 
				tail->next=new termNode;
				tail->next->data=x;
				tail->next->prev=tail;
				tail->next->next=NULL;
				tail=tail->next;
			}
			++count;
		}
		errorInfo mergeAdjacent(termNode* t){//��������t�Ľڵ����ڽ��Ĳ������ڵ�ϲ�������ֵ 
			termNode* begin;//�ϲ���ϵ�ǰ�ڵ� 
			termNode* end;//�ϲ���ϵ��ڵ� 
			termNode* del;//��ɾ����ڵ� 
			termNode* del2=NULL;//��ɾ���ҽڵ� 
			double val_double;//���渡���͵������� 
			int val_int;//�������������� 
			int i1,i2;//��ȡ���β��� 
			double d1,d2;//��ȡ�����Ͳ��� 
			switch((t->data).category){//��������category���Բ�ͬ���ϲ���ʽ��ͬ 
				case term::L:
					del=t;
					begin=t->prev;
					end=t->next;//���úöϵ�λ�úʹ�ɾ�ڵ��λ�� 
					if((t->data).attribute==term::uniInt){//���ݺ��������� 
						if(begin->data.attribute==term::Int){//�Բ����������ͼ�� 
							i1=begin->data.val.ival;
							val_int=((t->data).val.ptr4)(i1);
						}
						else{
							errorInfo tmp;
							tmp.errCode=8;
							tmp.position=begin->data.position;
							return tmp;
						}
						begin->data.category=term::None;//�������������ںϲ���Ľڵ��� 
						begin->data.attribute=term::Int;
						begin->data.val.ival=val_int;
					}
					else if((t->data).attribute==term::uniDouble){
						if(begin->data.attribute==term::Int){//ʵ�����������Ͳ��� 
							i1=begin->data.val.ival;
							val_double=((t->data).val.ptr2)(i1);
						}
						else if(begin->data.attribute==term::Float){
							d1=begin->data.val.dval;
							val_double=((t->data).val.ptr2)(d1);
						}
						else{
							errorInfo tmp;
							tmp.errCode=10;
							tmp.position=begin->data.position;
							return tmp;
						}
						begin->data.category=term::None;
						if(equal(val_double,(int)val_double)){//�������������ӽ���������Ϊ������Ϊ���� 
							begin->data.attribute=term::Int;
							begin->data.val.ival=(int)val_double;
						}
						else{
							begin->data.attribute=term::Float;
							begin->data.val.dval=val_double;
						}
					}
					break;
				case term::R://�����������Ͳ������Ĵ���ԭ������ 
					begin=t;
					end=t->next->next;
					del=t->next;
					if((t->data).attribute==term::uniInt){
						if(del->data.attribute==term::Int){
							i1=del->data.val.ival;
							val_int=((t->data).val.ptr4)(i1);
						}
						else{
							errorInfo tmp;
							tmp.errCode=8;
							tmp.position=del->data.position;
							return tmp;
						}
						begin->data.category=term::None;
						begin->data.attribute=term::Int;
						begin->data.val.ival=val_int;
					}
					else if((t->data).attribute==term::uniDouble){
						if(del->data.attribute==term::Int){
							i1=del->data.val.ival;
							val_double=((t->data).val.ptr2)(i1);
						}
						else if(del->data.attribute==term::Float){
							d1=del->data.val.dval;
							val_double=((t->data).val.ptr2)(d1);
						}
						else{
							errorInfo tmp;
							tmp.errCode=10;
							tmp.position=del->data.position;
							return tmp;
						}
						begin->data.category=term::None;
						if(equal(val_double,(int)val_double)){
							begin->data.attribute=term::Int;
							begin->data.val.ival=(int)val_double;
						}
						else{
							begin->data.attribute=term::Float;
							begin->data.val.dval=val_double;
						}				
					}
					break;
				case term::LR:
					begin=t->prev;
					end=t->next->next;
					del=t;
					del2=t->next;
					if((t->data).attribute==term::biDouble){
						if(begin->data.attribute==term::Int&&del2->data.attribute==term::Int){
							i1=begin->data.val.ival;
							i2=del2->data.val.ival;
							val_double=((t->data).val.ptr1)(i1,i2);
						}
						else if(begin->data.attribute==term::Int&&del2->data.attribute==term::Float){
							i1=begin->data.val.ival;
							d1=del2->data.val.dval;
							val_double=((t->data).val.ptr1)(i1,d1);
						}
						else if(begin->data.attribute==term::Float&&del2->data.attribute==term::Int){
							d1=begin->data.val.dval;
							i1=del2->data.val.ival;
							val_double=((t->data).val.ptr1)(d1,i1);
						}
						else if(begin->data.attribute==term::Float&&del2->data.attribute==term::Float){
							d1=begin->data.val.dval;
							d2=del2->data.val.dval;
							val_double=((t->data).val.ptr1)(d1,d2);
						}
						else{
							errorInfo tmp;
							tmp.errCode=11;
							if(begin->data.attribute!=term::Int&&begin->data.attribute!=term::Float){
								tmp.position=begin->data.position;
							}
							else if(del2->data.attribute!=term::Int&&del2->data.attribute!=term::Float){
								tmp.position=del2->data.position;
							}
							return tmp;
						}
						begin->data.category=term::None;
						if(equal(val_double,(int)val_double)){
							begin->data.attribute=term::Int;
							begin->data.val.ival=(int)val_double;
						}
						else{
							begin->data.attribute=term::Float;
							begin->data.val.dval=val_double;
						}		
					}
					else if((t->data).attribute==term::biInt){
						if(begin->data.attribute==term::Int&&del2->data.attribute==term::Int){
							i1=begin->data.val.ival;
							i2=del2->data.val.ival;
							val_int=((t->data).val.ptr3)(i1,i2);
						}
						else{
							errorInfo tmp;
							tmp.errCode=9;
							if(begin->data.attribute!=term::Int){
								tmp.position=begin->data.position;
							}
							else if(del2->data.attribute!=term::Int){
								tmp.position=del2->data.position;
							}
							return tmp;
						}
						begin->data.category=term::None;
						begin->data.attribute=term::Int;
						begin->data.val.ival=val_int;
					}
					break;
				case term::RR:
					begin=t;
					end=t->next->next->next;
					del=t->next;
					del2=t->next->next;
					if((t->data).attribute==term::biDouble){
						if(del->data.attribute==term::Int&&del2->data.attribute==term::Int){
							i1=del->data.val.ival;
							i2=del2->data.val.ival;
							val_double=((t->data).val.ptr1)(i1,i2);
						}
						else if(del->data.attribute==term::Int&&del2->data.attribute==term::Float){
							i1=del->data.val.ival;
							d1=del2->data.val.dval;
							val_double=((t->data).val.ptr1)(i1,d1);
						}
						else if(del->data.attribute==term::Float&&del2->data.attribute==term::Int){
							d1=del->data.val.dval;
							i1=del2->data.val.ival;
							val_double=((t->data).val.ptr1)(d1,i1);
						}
						else if(del->data.attribute==term::Float&&del2->data.attribute==term::Float){
							d1=del->data.val.dval;
							d2=del2->data.val.dval;
							val_double=((t->data).val.ptr1)(d1,d2);
						}
						else{
							errorInfo tmp;
							tmp.errCode=11;
							if(del->data.attribute!=term::Int&&del->data.attribute!=term::Float){
								tmp.position=del->data.position;
							}
							else if(del2->data.attribute!=term::Int&&del2->data.attribute!=term::Float){
								tmp.position=del2->data.position;
							}
							return tmp;
						}
						begin->data.category=term::None;
						if(equal(val_double,(int)val_double)){
							begin->data.attribute=term::Int;
							begin->data.val.ival=(int)val_double;
						}
						else{
							begin->data.attribute=term::Float;
							begin->data.val.dval=val_double;
						}
					}
					else if((t->data).attribute==term::biInt){
						if(del->data.attribute==term::Int&&del2->data.attribute==term::Int){
							i1=del->data.val.ival;
							i2=del2->data.val.ival;
							val_int=((t->data).val.ptr3)(i1,i2);
						}
						else{
							errorInfo tmp;
							tmp.errCode=9;
							if(del->data.attribute!=term::Int){
								tmp.position=del->data.position;
							}
							else if(del2->data.attribute!=term::Int){
								tmp.position=del2->data.position;
							}
							return tmp;
						}
						begin->data.category=term::None;
						begin->data.attribute=term::Int;
						begin->data.val.ival=val_int;
					}
					break;
				default:;
			}
			begin->next=end;//�����ֵ�󣬽��ϵ�ǰ��ڵ���� 
			if(end!=NULL){//���ϵ��ڵ���ʵ��ڵ� 
				end->prev=begin;
			}
			else{//����˵��β�ڵ��Ǵ�ɾ�ڵ㣬��ʱ����β�ڵ� 
				tail=begin;
			}
			delete del;//ɾ����ɾ�ڵ� 
			--count;
			if(del2!=NULL){//����������ɾ�ڵ� 
				delete del2;
				--count;
			}
			errorInfo tmp;
			tmp.errCode=-1;
			return tmp;
		}
		void print(){//��δ�ӡÿ��termԪ�ص���Ϣ 
			termNode* p=front;
			while(p!=NULL){
				p->data.print();
				p=p->next;
			}
		}
	};

	struct OprQueue{//������ȼ����� 
		queue<termNode*> zeroOrder;
		queue<termNode*> firstOrder;
		queue<termNode*> secondOrder;
		queue<termNode*> thirdOrder;
	};

	struct expression{//���ʽ�ṹ�� 
		termList expr;//����������������ɵ����� 
		OprQueue opr;//������ָ�빹�ɵ��ļ����ȼ����� 
		
		//�������﷨��Ԫ���뵽���ʽ�� 
		void push(int val,int pos){//���ͱ����ļ��� 
			term* tmp=new term;//������ʱ���� 
			tmp->attribute=term::Int;//�趨��ֵ��������Ϣ 
			tmp->val.ival=val;
			tmp->category=term::None;
			tmp->position=pos;//�趨��λ��Ϣ 
			expr.push(*tmp);//���뵽������ 
		}
		void push(double val,int pos){//�����ͱ����ļ��� 
			term* tmp=new term;
			tmp->attribute=term::Float;
			tmp->val.dval=val;
			tmp->category=term::None;
			tmp->position=pos;
			expr.push(*tmp);
		}
		void push(char ch,int pos){//��ѧ������ļ��� 
			term* tmp=new term;
			switch(ch){
				case '+':
					tmp->attribute=term::biDouble;
					tmp->val.ptr1=Add;//�趨����ָ�� 
					tmp->category=term::LR;//�趨�������� 
					tmp->position=pos;
					expr.push(*tmp);
					opr.thirdOrder.push(expr.tail);//���������˲��������⣬����Ҫ������� 
					break;
				case '-':
					tmp->attribute=term::biDouble;
					tmp->val.ptr1=Minus;
					tmp->category=term::LR;
					tmp->position=pos;
					expr.push(*tmp);
					opr.thirdOrder.push(expr.tail);
					break;
				case '*':
					tmp->attribute=term::biDouble;
					tmp->val.ptr1=Multiply;
					tmp->category=term::LR;
					tmp->position=pos;
					expr.push(*tmp);
					opr.secondOrder.push(expr.tail);
					break;
				case '/':
					tmp->attribute=term::biDouble;
					tmp->val.ptr1=Divide;
					tmp->category=term::LR;
					tmp->position=pos;
					expr.push(*tmp);
					opr.secondOrder.push(expr.tail);
					break;
				case '^':
					tmp->attribute=term::biDouble;
					tmp->val.ptr1=pow;
					tmp->category=term::LR;
					tmp->position=pos;
					expr.push(*tmp);
					opr.firstOrder.push(expr.tail);
					break;
				case '!':
					tmp->attribute=term::uniInt;
					tmp->val.ptr4=Factorial;
					tmp->category=term::L;
					tmp->position=pos;
					expr.push(*tmp);
					opr.zeroOrder.push(expr.tail);
					break;
				case '%':
					tmp->attribute=term::biInt;
					tmp->val.ptr3=Mod;
					tmp->category=term::LR;
					tmp->position=pos;
					expr.push(*tmp);
					opr.secondOrder.push(expr.tail);
					break;
				default:cout<<"Error: Unidentified operator."<<endl;
			}
		}
		void push(double(*p)(double,double),int pos){//���ڸ��ຯ��ָ��Ĵ��� 
			term* tmp=new term;
			tmp->attribute=term::biDouble;
			tmp->val.ptr1=p;
			tmp->category=term::RR;
			tmp->position=pos;
			expr.push(*tmp);
			opr.zeroOrder.push(expr.tail);
		}
		void push(double(*p)(double),int pos){
			term* tmp=new term;
			tmp->attribute=term::uniDouble;
			tmp->val.ptr2=p;
			tmp->category=term::R;
			tmp->position=pos;
			expr.push(*tmp);
			opr.zeroOrder.push(expr.tail);
		}
		void push(int(*p)(int,int),int pos){
			term* tmp=new term;
			tmp->attribute=term::biInt;
			tmp->val.ptr3=p;
			tmp->category=term::RR;
			tmp->position=pos;
			expr.push(*tmp);
			opr.zeroOrder.push(expr.tail);
		}
		void push(int(*p)(int),int pos){
			term* tmp=new term;
			tmp->attribute=term::uniInt;
			tmp->val.ptr4=p;
			tmp->category=term::R;
			tmp->position=pos;
			expr.push(*tmp);
			opr.zeroOrder.push(expr.tail);
		}
		void push(double(*p)(double[],int),int pos){
			term* tmp=new term;
			tmp->attribute=term::Array;
			tmp->val.ptr5=p;
			tmp->category=term::R;
			tmp->position=pos;
			expr.push(*tmp);
			opr.zeroOrder.push(expr.tail);
		}
		errorInfo calculate(){//���ʽ�ļ��� 
			errorInfo err;
			err.errCode=-1;
			while(!opr.zeroOrder.isEmpty()){//���ȶ�ȡ������ȼ����� 
				err=expr.mergeAdjacent(opr.zeroOrder.pop());//����������ȼ���������ҽ��� 
				if(err.errCode!=-1)return err;
			}
			while(!opr.firstOrder.isEmpty()){
				err=expr.mergeAdjacent(opr.firstOrder.pop());//�������ȼ��Ӹߵ��ͣ�˳������ҵķ�ʽ�������� 
				if(err.errCode!=-1)return err;
			}
			while(!opr.secondOrder.isEmpty()){
				err=expr.mergeAdjacent(opr.secondOrder.pop());
				if(err.errCode!=-1)return err;
			}
			while(!opr.thirdOrder.isEmpty()){
				err=expr.mergeAdjacent(opr.thirdOrder.pop());
				if(err.errCode!=-1)return err;
			}
			return err;
		}
		void print(){//��ӡ���ʽ����˳���ӡtermList�е�Ԫ�� 
			expr.print();
		}
	};

	struct result{//���ڱ�ʾ��������ֵ���Ƿ���� 
		double value;
		bool error;
	};
	
	struct function{//�����ṹ�� 
		char tag[nameLength];//������ 
		term opr;//������ 
	};
	
	
	struct matchTree{//������ƥ������������ƽ����������� 
		struct treeNode{//���ڵ� 
			function func;
			treeNode* lch;
			treeNode* rch;
		};
		treeNode* root;//���ڵ� 
		void createNode(treeNode*& t,function f[],int lower,int upper){
			int mid;
			if(lower<=upper){
				t=new treeNode;
				mid=(lower+upper)/2;//�����ź�������飬�ݹ����������ֵ��Ϊ���ڵ��ֵ�����ɽ���ƽ����������� 
				tagCopy(t->func.tag,f[mid].tag);//�趨��ǰ�ڵ��function����ĺ�����tag 
				t->func.opr.attribute=f[mid].opr.attribute;//�趨function����Ĳ��������� 
				t->func.opr.category=f[mid].opr.category;
				switch(t->func.opr.attribute){//Ϊfunction������亯��ָ�� 
					case term::biDouble:
						t->func.opr.val.ptr1=f[mid].opr.val.ptr1;
						break;
					case term::uniDouble:
						t->func.opr.val.ptr2=f[mid].opr.val.ptr2;
						break;
					case term::biInt:
						t->func.opr.val.ptr3=f[mid].opr.val.ptr3;
						break;
					case term::uniInt:
						t->func.opr.val.ptr4=f[mid].opr.val.ptr4;
					case term::Array:
						t->func.opr.val.ptr5=f[mid].opr.val.ptr5;
						break;
					default:
						cout<<"Failed to construct the function table.";
				}
				createNode(t->lch,f,lower,mid-1);//�ݹ�ؽ����ڵ� 
				createNode(t->rch,f,mid+1,upper);
			}
		}
		void releaseNode(treeNode*& t){//�ݹ��ɾ����tΪ�������� 
			if(t!=NULL){
				releaseNode(t->lch);
				releaseNode(t->rch);
				delete t;
			}
		}
		matchTree(function f[],int n){//���캯���ݹ����createNode 
			createNode(root,f,0,n-1);
		}
		~matchTree(){//�������� 
			releaseNode(root);
		}
	};
	
	bool err;//�������Ĵ����־ 
	int errCode;//�������־ 
	function functionTable[100];//������֧�ֵĺ����� 
	matchTree *fTree;//�������ĺ�����ƥ���� 
	char errMsg[20][100]={//������������Ϣ�� 
		"Unexpected ','.",
		"')' not matched.",
		"Unidentified token.",
		"Unexpected '.'.",
		"Digit numbers required after '.'.",
		"Only '+' and '-' allowed at the beginning of the expression.",
		"Illegal character after an operator.",
		"'!!' is not supported in this program.",
		"Function int (int) can not take a parameter of type double.",
		"Function int (int,int) can not take a parameter of type double.",
		"Function double (double) taking a parameter of wrong type: implication of syntax error.",
		"Function double (double,double) taking a parameter of wrong type: implication of syntax error.",
		"Operands missing.",
		"Function not defined.",
		"Parameter(s) missing.",
		"'()' required after a function.",
		"Too few parameter(s).",
		"Too many parameters.",
		"Illegal characters.",
		"Expression not finished."
	};
	
	struct val{//isSet��ʾ��Ԫ���Ƿ񱻳�ʼ�������Ƿ񱻸���ֵ��value���渳ֵ�����ں����Ļ��ֲ����ı��� 
		bool isSet=false;
		double value;
	};
	
	void readNumber(char* ch,int& i,expression& e,bool omit=false){//���ַ�����ԼΪ���֣����뵽���ʽe�У�omitΪ���ʾ��������Ϊ���ұ�ʡ�� 
		int ival=0;
		int orig;
		if(!omit){//��������δʡ�Ե���� 
			orig=i;
			ival=ch[i]-'0';
			while(isNumber(ch[++i])){
				ival=ival*10+ch[i]-'0';//��Լ����ֵ 
			}
			if(ch[i]=='\0'){//�������ֺ�����ַ������﷨���� 
				e.push(ival,orig);//�Ϸ��߽���ֵ������ʽ 
				return;//����calculate���� 
			}
			else if(isOperator(ch[i])){
				e.push(ival,orig);
				return;
			}
			else if(isAlphabet(ch[i])){
				e.push(ival,orig);
				e.push('*',i);//���������Ĳ���ʡ�Եĳ˺� 
				return;
			}
			else if(ch[i]==','){//���ڷǷ��ַ������෵�ش�����Ϣ 
				err=true;
				errCode=0;
				return;
			}
			else if(ch[i]==')'){
				err=true;
				errCode=1;
				return;
			}
			else if(ch[i]=='('){
				e.push(ival,orig);
				e.push('*',i);
				return;
			}
			else if(ch[i]=='.'){//����С���㣬ʲôҲ������ִ�������С�����ִ������ 
				;
			}
			else{
				err=true;
				errCode=2;
				return;
			}	
		}
		if(isNumber(ch[++i])){//С�������������� 
			if(omit)orig=i;
			double dval=0;
			double deci=1.0/10;
			do{
				dval+=(ch[i++]-'0')*deci;
				deci=deci/10;//��ԼС������ 
			}while(isNumber(ch[i]));
			dval+=ival;//������������С��������� 
			e.push(dval,orig);//�����������ʽe�� 
			if(ch[i]=='\0'){//�������ַ��Ƿ�Ϸ� 
				return;
			}
			else if(isOperator(ch[i])){
				return;
			}
			else if(isAlphabet(ch[i])){
				e.push('*',i);
				return;
			}
			else if(ch[i]==','){
				err=true;
				errCode=0;
				return;
			}
			else if(ch[i]=='('){
				e.push('*',i);
				return;
			}
			else if(ch[i]==')'){
				err=true;
				errCode=1;
				return;
			}
			else if(ch[i]=='.'){
				err=true;
				errCode=3;
				return;
			}
			else{
				err=true;
				errCode=2;
				return;
			}
		}
		else{
			err=true;
			errCode=4;
			return;
		}
	}
	int readFunction(char* ch,int& i,expression& e,int offset){//���ں����ַ������й�Լ 
		int orig=i;
		term func=match(ch,i);//ƥ�亯���� 
		if(func.val.ptr1==Fail){
			i=func.position;
			return -1;
		}
		int rlt=readParameter(ch,i,e,&func,orig,offset);//��ȡ���� 
		if(rlt==-1){//����ֵ-1��ʾreadParameter��δǶ�׵���calculate����������·����˴��󣬸ô�����Ϣδ��ӡ����Ҫ�����ϼ�calculate�������д��� 
			return -1;
		}
		else if(rlt==-2){//����readParameterǶ�׵���calculate����ʱ�����˴��󣬸ô�����Ϣ�Ѿ���ӡ���������ϼ�calculate������Ӧ��ֱ���˳� 
			return -2;
		}
		return 0;
	}
	void readOperator(char* ch,int& i,expression& e){//��Լ��������� 
		if(e.expr.tail==NULL){//��ͷ�������ֻ����+ - 
			if(ch[i]!='+'&&ch[i]!='-'){
				err=true;
				errCode=5;
				return;
			}
			else if(ch[i]=='+'){//+ ������Ϊ�Ϸ��ַ���ֱ������ + 
				++i;
				if(isNumber(ch[i])||isAlphabet(ch[i])||ch[i]=='.'||ch[i]=='('){
					return;
				}
				else if(ch[i]=='\0'){
					err=true;
					errCode=12;
					return;
				}
				else{
					err=true;
					errCode=6;
					return;
				}
			}
			else{//����ͷ���ֵļ������Ϊǰ����һ��ʡ�Ե��� 
				++i;
				if(isNumber(ch[i])||isAlphabet(ch[i])||ch[i]=='.'||ch[i]=='('){
					e.push(0,i-1);//����ʡ�� 
					e.push('-',i-1);//�ٽ�������ӵ����ʽ�� 
					return;
				}
				else if(ch[i]=='\0'){//�����﷨������ķ��ദ�� 
					err=true;
					errCode=12;
					return;
				}
				else{
					err=true;
					errCode=6;
					return;
				}
			}
		}
		else{//���ǿ�ͷ���ֵ�������������ǲ���!���з��ദ�� 
			if(ch[i]!='!'){
				if(isNumber(ch[i+1])||isAlphabet(ch[i+1])||ch[i+1]=='.'||ch[i+1]=='('){//˫Ŀ�����������������������﷨��Ԫ 
					e.push(ch[i],i);
					++i;
					return;
				}
				else if(ch[i+1]=='\0'){//������� 
					err=true;
					errCode=12;
					return;
				}
				else{
					err=true;
					errCode=6;
					return;
				}
			}
			else{//!������Գ����������﷨��Ԫ 
				++i;
				if(isNumber(ch[i])||isAlphabet(ch[i])||ch[i]=='.'||ch[i]=='('){
					e.push('!',i-1);
					e.push('*',i-1);
					return;
				}
				else if(ch[i]=='\0'){//����ֱ�ӽ�β 
					e.push('!',i-1);
					return;
				}
				else if(isOperator(ch[i])){
					if(ch[i]=='!'){//����д!! 
						err=true;
						errCode=7;
						return;
					}
					else{//���Խ�˫Ŀ����� 
						if(isNumber(ch[i+1])||isAlphabet(ch[i+1])||ch[i+1]=='.'||ch[i+1]=='('){//��˫Ŀ����������������������﷨��Ԫ�źϷ� 
							e.push('!',i-1);
							e.push(ch[i],i);
							++i;
							return;
						}
						else if(ch[i+1]=='\0'){
							err=true;
							errCode=12;
							return;
						}
						else{
							err=true;
							errCode=6;
							return;
						}
					}
				}
				else{
					err=true;
					errCode=6;
					return;
				}
			}
		}
	}
	term match(char* ch,int& i){//������ƥ�� 
		int j=0;
		int orig=i;
		matchTree::treeNode* node=fTree->root;//��ƥ�����ĸ��ڵ㿪ʼ���� 
		while(isAlphabet(ch[i])||node->func.tag[j]!='\0'){//��ȡ���ַ�����ƥ������tag��������һ��û��ƥ����� 
			while(node!=NULL){
				if(!isAlphabet(ch[i])){//�����ĸ���Ѿ���ȡ��ϣ�tag���ַ���ȴû�ж�ȡ��ϣ��п�����ĸ����sin��tagΪsinh����ʱ����ĸ����Ϊ******\0��\0С�������κ��ַ������Ӧ�����������м���ƥ����� 
					i=orig;
					j=0;
					node=node->lch;
				}
				else if(ch[i]>node->func.tag[j]){//�ڵ���ת��i,j������ݵ����λ�� 
					i=orig;
					j=0;
					node=node->rch;
				}
				else if(ch[i]<node->func.tag[j]){
					i=orig;
					j=0;
					node=node->lch;
				}
				else if(ch[i]==node->func.tag[j]){//��ǰ�ַ�ƥ��ɹ�������ƥ����һ�ַ� 
					++i;
					++j;
					break;
				}
			}
			if(node==NULL)break;
		}
		if(node==NULL){//ƥ��ʧ�ܣ�����Fail����ָ�� 
			err=true;
			errCode=13;
			term tmp;
			tmp.val.ptr1=Fail;
			tmp.attribute=term::biDouble;
			tmp.category=term::RR;
			tmp.position=orig;
			return tmp;
		}
		else if(!isAlphabet(ch[i])&&node->func.tag[j]=='\0'){//��ĸ���պý�����tag�ַ���Ҳ�պý�����˵��ƥ��ɹ� 
			term tmp;
			tmp.attribute=node->func.opr.attribute;
			tmp.category=node->func.opr.category;
			tmp.position=orig;
			switch(node->func.opr.attribute){//��function�ڵ�ĺ���ָ�븳��term���� 
				case term::biDouble:
					tmp.val.ptr1=node->func.opr.val.ptr1;
					break;
				case term::uniDouble:
					tmp.val.ptr2=node->func.opr.val.ptr2;
					break;
				case term::biInt:
					tmp.val.ptr3=node->func.opr.val.ptr3;
					break;
				case term::uniInt:
					tmp.val.ptr4=node->func.opr.val.ptr4;
				case term::Array:
					tmp.val.ptr5=node->func.opr.val.ptr5;
					break;
				default:
					cout<<"Exception";
			}
			return tmp;
		}
		else{//����˵��ƥ��ʧ�ܣ�����Fail����ָ�� 
			err=true;
			errCode=13;
			term tmp;
			tmp.val.ptr1=Fail;
			tmp.attribute=term::biDouble;
			tmp.category=term::RR;
			tmp.position=orig;
			return tmp;
		}
	}
	int readParameter(char* ch,int& i,expression& e,term* t,int begin,int offset){//��ȡ�������� 
		if(ch[i]=='\0'){
			err=true;
			errCode=14;
			return -1;
		}
		else if(ch[i]!='('){
			err=true;
			errCode=15;
			return -1;
		}
		else{
			int lbr=0;//�����ַ����е��������Ž��м��� 
			int rbr=0;
			int paraNum;
			if(t->attribute==term::uniDouble||t->attribute==term::uniInt){//���ݺ�����ƥ��õ��ĺ�����������Ϣ�����ò����������� 
				paraNum=1;
			}
			else if(t->attribute==term::biDouble||t->attribute==term::biInt){
				paraNum=2;
			}
			else if(t->attribute==term::Array){//�������������ĺ���������������Ϊ1024 
				paraNum=1024;
			}
			double para[paraNum];//������������ 
			int paraCnt;//ͳ��ʵ�ʳ��ֵĲ������� 
			bool integral=false;//�����﷨�ж��û��Ƿ�Ҫ����� 
			val intVal[paraNum][3];//�Ի������ޡ����ޡ��������б��� 
			if(ch[i+1]==')'){//��������Ϊ�գ�ʵ�ʲ�������Ϊ0 
				paraCnt=0;
			}
			else{
				int orig=i;
				paraCnt=1;
				int iParaCnt=0;
				while(rbr<=lbr){//�����ż�������������ʱ��������Լ���� 
					++i;
					if(ch[i]=='('){//�����Ž��м��� 
						++lbr;
					}
					else if(ch[i]==')'){
						++rbr;
					}
					if(ch[i]=='\0'){//���ʽ������ 
						err=true;
						errCode=19;
						return -1;
					}
					if(lbr==rbr&&ch[i]==':'){//�м����: �����û�Ҫ���л��ֲ��� 
						integral=true;
						intVal[paraCnt-1][iParaCnt].value=calculate(substr(ch,orig,i),offset+orig+1).value;//�����š�ð�š����Ÿ������ַ�����Լ��ֵ�������ڻ����������� 
						intVal[paraCnt-1][iParaCnt].isSet=true;
						++iParaCnt;
						orig=i;
					}
					if(lbr==rbr&&ch[i]==','){//�������ŷָ�������� 
						++paraCnt;
						if(paraCnt>paraNum){//�����������Ƿ񳬳�Ӧ��ֵ 
							err=true;
							errCode=17;
							return -1;
						}
						else{
							if(!integral){//�ǻ�������£���ǰһ��������ֵ�����ڲ��������� 
								result r=calculate(substr(ch,orig,i),offset+orig+1);
								if(!r.error){
									para[paraCnt-2]=r.value;
								}
								else{
									return -2;
								}
								orig=i;
							}
							else{//��������£���ǰһ�������Ĳ�����Ϣ�����ڻ����������� 
								intVal[paraCnt-2][iParaCnt].value=calculate(substr(ch,orig,i),offset+orig+1).value;
								intVal[paraCnt-2][iParaCnt].isSet=true;
								orig=i;
								iParaCnt=0;
							}
						}
					}
				}
				//�������ź� 
				if(!integral){//�ǻ��������£������һ������������ֵ 
					result r=calculate(substr(ch,orig,i),offset+orig+1);
					if(!r.error){
						para[paraCnt-1]=r.value;
					}
					else{
						return -2;//��Ƕ�׵�calculate��ֵ�������󣬷���ֵΪ-2 
					}
				}
				else{//���������£������һ�������Ĳ�����Ϣ�����ڻ����������� 
					intVal[paraCnt-1][iParaCnt].value=calculate(substr(ch,orig,i),offset+orig+1).value;
					intVal[paraCnt-1][iParaCnt].isSet=true;
					orig=i;
					double fSum=0.0;
					if(paraNum==1){//����Ӧ�в����ĸ������л��ֽ�����ֵ 
						for(double d=intVal[0][0].value;d<=intVal[0][1].value;d+=intVal[0][2].value){
							fSum+=t->val.ptr2(d);
						}
						fSum=fSum*intVal[0][2].value;
						e.push(fSum,begin);
					}
					else if(paraNum==2){
						for(double d1=intVal[0][0].value;d1<=intVal[0][1].value;d1+=intVal[0][2].value){
							for(double d2=intVal[1][0].value;d2<=intVal[1][1].value;d2+=intVal[1][2].value){
								fSum+=t->val.ptr1(d1,d2);
							}
						}
						fSum=fSum*intVal[0][2].value*intVal[1][2].value;
						e.push(fSum,begin);
					}
					++i;
					if(isNumber(ch[i])||isAlphabet(ch[i])||ch[i]=='.'||ch[i]=='('){//������������ַ��Ƿ�Ϸ����Ƿ���Ҫ�������� 
						e.push('*',i);
						return 0;
					}
					else if(isOperator(ch[i])||ch[i]=='\0'){
						return 0;
					}
					else{
						err=true;
						errCode=18;
						return -1;
					}
				}	
			}
			if(paraCnt<paraNum&&paraNum!=1024){//���ڲ��������̶��ĺ����������������ͳ�ƶ���Ӧ�в������� 
				err=true;
				errCode=16;
				return -1;
			}
			switch(t->attribute){//����ȡ�õ��Ĳ������뵽����ָ���н��м��� 
				case term::biDouble:
					if(equal(t->val.ptr1(para[0],para[1]),(int)t->val.ptr1(para[0],para[1]))){//�������Ϊ�����ģ���Ϊ���ͱ��� 
						e.push((int)t->val.ptr1(para[0],para[1]),begin);
					}
					else{
						e.push(t->val.ptr1(para[0],para[1]),begin);
					}
					break;
				case term::uniDouble:
					if(equal(t->val.ptr2(para[0]),(int)t->val.ptr2(para[0]))){
						e.push((int)t->val.ptr2(para[0]),begin);
					}
					else{
						e.push(t->val.ptr2(para[0]),begin);
					}
					break;
				case term::biInt:
					e.push(t->val.ptr3(para[0],para[1]),begin);
					break;
				case term::uniInt:
					e.push(t->val.ptr4(para[0]),begin);
					break;
				case term::Array:
					if(equal(t->val.ptr5(para,paraCnt),(int)t->val.ptr5(para,paraCnt))){//�����������̶��ĺ����Ĳ��� 
						e.push((int)t->val.ptr5(para,paraCnt),begin);
					}
					else{
						e.push(t->val.ptr5(para,paraCnt),begin);
					}
					break;
				default:cout<<"Error";
			}
			++i;
			if(isNumber(ch[i])||isAlphabet(ch[i])||ch[i]=='.'||ch[i]=='('){//��������ַ��ĺϷ��� 
				e.push('*',i);
				return 0;
			}
			else if(isOperator(ch[i])||ch[i]=='\0'){
				return 0;
			}
			else{
				err=true;
				errCode=18;
				return -1;
			}		
		}
	}
public:
	calculator(){//calculator�Ĺ��캯�� 
		tagCopy(functionTable[0].tag,"abs");//��������������tag�ַ��������ֵ����������� 
		tagCopy(functionTable[1].tag,"acos");
		tagCopy(functionTable[2].tag,"asin");
		tagCopy(functionTable[3].tag,"atan");
		tagCopy(functionTable[4].tag,"avg");
		tagCopy(functionTable[5].tag,"cbrt");
		tagCopy(functionTable[6].tag,"cos");
		tagCopy(functionTable[7].tag,"cosh");
		tagCopy(functionTable[8].tag,"exp");
		tagCopy(functionTable[9].tag,"ln");
		tagCopy(functionTable[10].tag,"log");
		tagCopy(functionTable[11].tag,"pow");
		tagCopy(functionTable[12].tag,"sd");
		tagCopy(functionTable[13].tag,"sin");
		tagCopy(functionTable[14].tag,"sinh");
		tagCopy(functionTable[15].tag,"sqrt");
		tagCopy(functionTable[16].tag,"sum");
		tagCopy(functionTable[17].tag,"tan");
		tagCopy(functionTable[18].tag,"tanh");
		tagCopy(functionTable[19].tag,"var");
		functionTable[0].opr.val.ptr2=fabs;//Ϊ������֧�ֵĺ���������Ӧ�����Ժͺ���ָ�� 
		functionTable[0].opr.attribute=term::uniDouble;
		functionTable[0].opr.category=term::R;
		functionTable[1].opr.val.ptr2=acos;
		functionTable[1].opr.attribute=term::uniDouble;
		functionTable[1].opr.category=term::R;
		functionTable[2].opr.val.ptr2=asin;
		functionTable[2].opr.attribute=term::uniDouble;
		functionTable[2].opr.category=term::R;
		functionTable[3].opr.val.ptr2=atan;
		functionTable[3].opr.attribute=term::uniDouble;
		functionTable[3].opr.category=term::R;
		functionTable[4].opr.val.ptr5=Average;
		functionTable[4].opr.attribute=term::Array;
		functionTable[4].opr.category=term::R;
		functionTable[5].opr.val.ptr2=cbrt;
		functionTable[5].opr.attribute=term::uniDouble;
		functionTable[5].opr.category=term::R;
		functionTable[6].opr.val.ptr2=cos;
		functionTable[6].opr.attribute=term::uniDouble;
		functionTable[6].opr.category=term::R;
		functionTable[7].opr.val.ptr2=cosh;
		functionTable[7].opr.attribute=term::uniDouble;
		functionTable[7].opr.category=term::R;
		functionTable[8].opr.val.ptr2=exp;
		functionTable[8].opr.attribute=term::uniDouble;
		functionTable[8].opr.category=term::R;
		functionTable[9].opr.val.ptr2=log;
		functionTable[9].opr.attribute=term::uniDouble;
		functionTable[9].opr.category=term::R;
		functionTable[10].opr.val.ptr2=log10;
		functionTable[10].opr.attribute=term::uniDouble;
		functionTable[10].opr.category=term::R;
		functionTable[11].opr.val.ptr1=pow;
		functionTable[11].opr.attribute=term::biDouble;
		functionTable[11].opr.category=term::RR;
		functionTable[12].opr.val.ptr5=Sd;
		functionTable[12].opr.attribute=term::Array;
		functionTable[12].opr.category=term::R;
		functionTable[13].opr.val.ptr2=sin;
		functionTable[13].opr.attribute=term::uniDouble;
		functionTable[13].opr.category=term::R;
		functionTable[14].opr.val.ptr2=sinh;
		functionTable[14].opr.attribute=term::uniDouble;
		functionTable[14].opr.category=term::R;
		functionTable[15].opr.val.ptr2=sqrt;
		functionTable[15].opr.attribute=term::uniDouble;
		functionTable[15].opr.category=term::R;
		functionTable[16].opr.val.ptr5=Sum;
		functionTable[16].opr.attribute=term::Array;
		functionTable[16].opr.category=term::R;
		functionTable[17].opr.val.ptr2=tan;
		functionTable[17].opr.attribute=term::uniDouble;
		functionTable[17].opr.category=term::R;
		functionTable[18].opr.val.ptr2=tanh;
		functionTable[18].opr.attribute=term::uniDouble;
		functionTable[18].opr.category=term::R;
		functionTable[19].opr.val.ptr5=Var;
		functionTable[19].opr.attribute=term::Array;
		functionTable[19].opr.category=term::R;
		fTree=new matchTree(functionTable,20);//�����湹���õ����鹹��ƽ����������� 
	}
	~calculator(){//�������� 
		delete fTree;
	}
	result calculate(char* ch,int offset=0){//�������ʽ�ַ�������ֵ�����庯����ʱ�临�Ӷ�һ��ΪO(n)���ΪO(n^2)���ռ临�Ӷ�һ��ΪO(n)���ΪO(n^2) 
		err=false;
		errCode=-1;//���ô����� 
		if(ch[0]=='\0'){//���ַ�������0 
			result tmp;
			tmp.value=0;
			tmp.error=false;
			return tmp;
		}
		int i=0;
		expression* e=new expression;//Ϊ�ַ���������ʽ 
		while(ch[i]!='\0'){
			if(isNumber(ch[i])){//��Լ���� 
				readNumber(ch,i,*e);
			}
			else if(ch[i]=='.'){//��Լʡ���������ֵ�С�� 
				readNumber(ch,i,*e,true);
			}
			else if(isOperator(ch[i])){//��Լ������ 
				readOperator(ch,i,*e);
			}
			else if(isAlphabet(ch[i])){//��Լ���� 
				int rlt=readFunction(ch,i,*e,offset);
				if(rlt==-2){//Ƕ�׵��õĴ���ֱ���˳�����ִ�й��� 
					result tmp;
					tmp.value=0;
					tmp.error=true;
					return tmp;
				}
			}
			else if(ch[i]=='('){//�������������ַ����Ĵ��� 
				int lbr=0;
				int rbr=0;
				int orig=i;
				while(rbr<=lbr){
					++i;
					if(ch[i]=='('){//�����Ž��м��� 
						++lbr;
					}
					if(ch[i]==')'){
						++rbr;
					}
					if(ch[i]=='\0'){
						err=true;
						errCode=1;
						i=orig;
						break;
					}
				}
				if(!err){
					result r=calculate(substr(ch,orig,i),orig+1);//���ַ�����ֵ 
					if(!r.error){
						if(equal(r.value,(int)r.value)){
							e->push((int)r.value,orig+1);
						}
						else{
							e->push(r.value,orig+1);
						}
						++i;
						if(isNumber(ch[i])||isAlphabet(ch[i])||ch[i]=='('||ch[i]=='.'){//����ʡ�Եĳ˺� 
							e->push('*',i);
						}
					}
					else{
						result tmp;
						tmp.value=0;
						tmp.error=true;
						return tmp;
					}
				}
			}
			else{
				err=true;
				errCode=2;
			}
			if(err){//���err�Ƿ񱻹�Լ��������Ϊtrue����ӡ������Ϣ 
				cout<<"Position:"<<offset+i+1<<" Error Code:"<<errCode<<endl<<errMsg[errCode];
				result tmp;
				tmp.value=0;
				tmp.error=true;
				return tmp;
			}
		}
		errorInfo eInfo=e->calculate();//�����ַ��������� 
		if(eInfo.errCode!=-1){//�����ڱ��ʽ��calculate����ִ�г��� 
			cout<<"Position:"<<offset+eInfo.position+1<<" Error Code:"<<eInfo.errCode<<endl<<errMsg[eInfo.errCode];
			result tmp;
			tmp.value=0;
			tmp.error=true;
			return tmp;
		}
		if(offset==0){//�������offsetΪ0��˵����calculate������Լ�����������ʽ����ʱ�������ʽ��Լ��ϣ��������������ӱ��ʽ��Լ��ϣ��������� 
			cout<<"=";
			e->print();
		}
		result tmp;//���췵��ֵ����Ϊ�ݹ��Ƕ�׵��÷��� 
		if(e->expr.front->data.attribute==term::Float){
			tmp.value=e->expr.front->data.val.dval;
		}
		else if(e->expr.front->data.attribute==term::Int){
			tmp.value=e->expr.front->data.val.ival;
		}
		tmp.error=false;
		delete e;
		return tmp;
	}
};

int main(){
	calculator c;
	char expr[1000];
	cout<<"Scientific Calculator"<<endl;//������ܽ��ܽ��� 
	cout<<"Operators supported: + - * / ^ % ! ()"<<endl;
	cout<<"Functions supported: abs acos asin atan avg cbrt cos cosh exp ln log pow sd sin sinh sqrt sum tan tanh var"<<endl;
	cout<<"Enter '@' to quit this program."<<endl;
	while(1){
		cin>>expr;
		if(expr[0]=='@'){
			break;
		}
		else{
			c.calculate(expr);
			cout<<endl;
		}
	}
	return 0;
}
