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

ע�⿴�����ע�͡�

06cpp :
main������ģʽ auto_ptr(ģ��)
main1��
#define sizeof_v(x)  ((char*)(&x+1) - (char*)&x )		//������С
#define sizeof_t(X)  (size_t)((X*)0 + 1)				//���ʹ�С
								
#define ALIGN(v, b)  ((v+b-1) & ~(b-1))				//���룬�����ڴ�غ�����

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


