01cpp:

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