01cpp:
C++�Ż������������۵�

const_cast����Ҫ�����ָ������ã�ȥ������ԭ�е�const����

ʹ��const_castȥ��const�޶���Ŀ�Ĳ���Ϊ���޸���������
ʹ��const_castȥ��const�޶���ͨ����Ϊ�˺����ܹ��������ʵ�ʲ����������ββ���const���ԣ�ʵ�δ�const���ԡ�

02cpp:

��Ҫʵ��String�࣬Ŀ��������������ء�
	String s1 = "abcd";		//���ù��캯����������캯�����explicit�Ͳ�������ʽת���ˡ�
	String s2 = s1;			//���ÿ������캯��
							//���߶�Ϊ���ø�ֵ=������
	����ʵ������������������أ�
	=��==��+��+=��[]������<<��>>��

03cpp:

��ֹ���������������캯���͸�ֵ������Ϊ˽�С�

Singletonģʽ��
	main1.cpp��ʵ���˵��������Ƕ��ڵ�������Դ�ͷ��������Ĳ��Ǻܺã��ھ���Ĺ����У��ڶ���ط��ô˵�������֪��ʱ�����ͷ���Դ������Ҫ��������Զ��ͷ���Դ�����⡣
	main2.cpp������Զ��ͷŵ�����Դ��������һ����Ƕ�࣬���ݴ�����������ȷ���ͽ����ͷš�
	main3.cpp�������˾ֲ�static �������󣬿��Խ����Դ�Զ��ͷŵ����⣬�������̰߳�ȫ�ġ�

04cpp��
��Ҫѧϰ��new(�ؼ���)�� operator new(����) �Լ� operator new�����ء�
http://www.cnblogs.com/luxiaoxun/archive/2012/08/10/2631812.html

void *operator new(size_t size);						//operator new ��ԭ��
void delete (void *p);
void delete (void *p, size_t);

void *operator new[](size_t size);						//operator new ����ԭ��
void delete[](void *p);

void *operator new(size_t size, void *p);				// placement new ��operator new ������
void delete(void *p, void *q);

void *operator new(size_t size, char *file, long line);	//���ص����
void delete(void *p, char *file, long line);

���������������������new��delete����ͬʱ���ж��壬������ʹ�õ�ʱ�������׵ġ�
�������׻����ǽ����new�����쳣ʱ���������׵�delete���õġ�
һ��ֻ����delete������ͨ��delete�������ҵ��Ǹ���Ӧ�ġ�

new operator = operator new + ���캯����

05cpp��
����ģʽ��ʵ��

ʲô�¹���ģʽ��

ע�⿴�����ע�͡�

06cpp :
main������ģʽ auto_ptr(ģ��)
main1��
#define sizeof_v(x)  ((char*)(&x+1) - (char*)&x )		//������С
#define sizeof_t(X)  (size_t)((X*)0 + 1)				//���ʹ�С
								
#define ALIGN(v, b)  ((v+b-1) & ~(b-1))					//���룬�����ڴ�غ�����

07cpp��
ѧϰ�򵥵�io����
io��Ϊ���֣�
��׼io���Ա�׼����������豸���������
	cin cout cerr clog
�ļ�io�����ⲿ�洢�е��ļ��������������
	ifstream ofstream fstream
	filebuf
��io��  ���ڴ��е�һ���ַ������������������
	istringstream ostringstream stringstream
	stringbuf

main: �ı���ʽ��������Ƹ�ʽ�򿪵�����
		windows�� д��'\n'��ת����'\r\n'
		linux :   '\n'���䣬Ҳ��˵��linux�������ı���ʽ�򿪺Ͷ����Ƹ�ʽ��ʱһ���ġ�
		mac ��     '\n' ��ת����'\r'��
		'\r'�������ĸ�ϵͳ�ж�����ת���ġ�

main1�� ����Ķ�д�ַ�����ʽ��
main2�� ��ȷ��ʽ֮һ��

08cpp:
��Ҫѧϰ�� stringstream ��io
istringstream: �����ַ�������һ����Ҫ��һ���ַ��������ڴ��ж�ȡ��
ostringstream: ����ַ�������һ�㲻��Ҫ���ַ��������뵽���е���Ϣ��������Լ�������ַ����������::str()����ȡ����

main01:
	ѭ����ȡ�����
main02:
	double���ַ���֮���ת����

09cpp��
	ʵ�ֲ����ӷ�ʽ�ͳ�Ա�������ַ�ʽ��
	��ȿ���
	�������
	������
	���ȿ���
	���ƿ���

10cpp:
	ģ���ѧϰ

	���ھ�����ͬ�߼��Ĵ��봦��Ŀǰ�����·�����
	1. �꣺ ���������ڲ�ͬ���Ͳ����á�
	2. ���أ� ����ÿ�����Ͷ�Ҫ��д���غ�����
	3. ģ�壺 �ȽϺõķ���

main01�� ����ģ�壬 ��Ԫ���� < �Ķ��塣
���	ģ�庯��			����Ϊ�߼�����һ�¶��������Ͳ�һ�µĸ��ֳ����ṩһ�ֵĴ��빲����ơ�
		ģ�庯���ػ�		��Ȼ��ģ�庯����ֻ�������Ǿ����ʵ���� template<>,��������Ϊ�սӿڣ������е����Ͷ���ָ���ġ�
		��ģ�庯������ 	��ȫ�ֺ����������������ȿ��ǣ�û�еĻ����Żῼ��ģ�庯����

main02��ȱʡģ�����
main03����Աģ�庯��������ģ���ˣ��������ڻ����������µ����ͣ�����ģ�庯����
		����const����������ȷ���˽⣺����()�����const����˼�ǽ�thisָ����ָ�������const����Ҳ��˵���������const���ˣ����ɸ��ġ�
		������Ƶ������롣
main04��typename���÷����������Ͳ���ʹ��������Ҫ����˼��

*******
�������÷�ʽ��
�����������������궨�塣
�̳�(׷����Ч��) MFC�����õ����ַ�ʽ��	��Ϸ�ʽ��
ģ��(׷������Ч�ʣ�����������ñ��������ˡ�) �����Ͳ�����ʹ�� �������������ĸ����stack������deque������Ч��Ҫ�ȼ̳еķ�ʽ�ߡ�

��������뷺�Ͷ�������ĳ����ʽ�Ķ�̬��
������� ��̬��̬  �麯��		����ʱ����������ڵ�ַ
���ͱ�̣� ��̬��̬  ģ��			���������˺�����ڵ�ַ

*******

11cpp:
	ģ��ĵ���ģʽѧϰ
	�̰߳�ȫ�ĵ���ģʽ�ࣺ��ͨ����double check lock��pthread_once(linux)

12cpp:
	Mysql����++ Connector example.
	1. mysql-workbench-community-6.0.9-win32
	2. mysql-connector-c1.0.5-winx64��û�ð���
	3. mysql-5.5.40-winx64

	source code�� 
	mysql-connector-c++-1.1.4
	boost_1_54_0
	MySQL Server 5.5[����include��lib�ļ���] ��λ�ã�������Ϊ MySQL_Server_5.5
	ʹ��cmake-3.0.2ת����Visual Studio 2012�湤�̣������dll�ļ���
	���̣�  1. set MYSQL_DIR=/path/to/Mysql_Server_5.5
		2. set BOOST_ROOT=/path/to/boost_1_34_0
			 ע���м䲻Ҫ�пո�
		3. cmake -G "Visual Studio 11 Win64"
		�������sln�ļ�ʹ��VS-2012�򿪡�

ClassTest:
	table���ʵ�֡�
